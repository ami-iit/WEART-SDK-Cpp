# List of modifications on WEART C++ SDK
_Note: These are the modification applied to the original version of the SDK which can be downloaded from [here](https://github.com/ami-iit/WEART-SDK-Cpp)._

### Created WeArtGloveLib.h :
This file is created to make it easier when you want to include the header files to your own project.(i.e. Just include this file in your main.cpp).

### WeArtCommon.h :
- Added the lines: 
```c++
#include <cstdint>   
typedef uint8_t uint8;  
```

### WeArtHapticObject.h :
- Changed lines:

```c++
int32  handSideFlag;
int32 actuationPointFlag;
```
to 
```c++
int32_t handSideFlag;
int32_t actuationPointFlag;
```

### WeArtClient.cpp :
- Added the lines:
```c++
#include <roapi.h>
#include <wrl.h>

#include <Windows.Foundation.h>
#include <Windows.System.Threading.h>
#include <wrl/event.h>
#include <stdio.h>
#include <Objbase.h>
```
- Added the lines:
```c++
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::System::Threading;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
```
- Removed the line: `include "pch.h"`
- Removed the line: `#include <windows.h>` (Duplicate)
- Removed the lines:
```c++
using namespace Windows::Foundation;
using namespace concurrency;  
using namespace Windows::Devices::Enumeration
```

- These lines: 
```c++
// receive data in background 
auto workItem = ref new Windows::System::Threading::WorkItemHandler([this](IAsyncAction^ workItem)
    {
        OnReceive();
    });

auto asyncAction = Windows::System::Threading::ThreadPool::RunAsync(workItem);
```
changed to
```c++
// Initialize the Windows Runtime.
RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
ComPtr<IThreadPoolStatics> threadPool;
HRESULT hr = GetActivationFactory(HStringReference(RuntimeClass_Windows_System_Threading_ThreadPool).Get(), &threadPool);
Event threadCompleted(CreateEventEx(nullptr, nullptr, CREATE_EVENT_MANUAL_RESET, WRITE_OWNER | EVENT_ALL_ACCESS));
hr = threadCompleted.IsValid() ? S_OK : HRESULT_FROM_WIN32(GetLastError());

// receive data in background
ComPtr<IAsyncAction> asyncAction;
hr = threadPool->RunAsync(Callback<IWorkItemHandler>([this, &threadCompleted](IAsyncAction* asyncAction) -> HRESULT
{
    OnReceive();

    // Set the completion event and return.
    SetEvent(threadCompleted.Get());
    return S_OK;

    }).Get(), &asyncAction);
```
- The line 
```c++
FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPWSTR>(&errorBuffer), 0, nullptr);
```
changed to 
```c++
FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPWSTR>(&errorBuffer), 0, nullptr);
```

### WeArtAnalogSensorData.cpp :
- Removed the line: `include "pch.h"`
