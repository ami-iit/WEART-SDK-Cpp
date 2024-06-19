/**
 * @file WeArtGloveLib.h
 * @authors Ehsan Ranjbari <ehsan.ranjbari@iit.it>
 * @copyright 2022 iCub Facility - Istituto Italiano di Tecnologia
 *            Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 * @date 2023
 * This file created to make it easier when you want to include the header files to y"our own project.
 */
#define NOMINMAX

#include <iostream>
#include <string>
#include <vector>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ppltasks.h>
#include <algorithm>

#undef NOMINMAX
//WeArtSDK

#include"MiddlewareStatusListener.h"
#include"WeArtClient.h"
#include"WeArtCommon.h"
#include"WeArtController.h"
#include"WeArtEffect.h"
#include"WeArtForce.h"
#include"WeArtHapticObject.h"
#include"WeArtMessageListener.h"
#include"WeArtMessages.h"
#include"WeArtMessageSerializer.h"
#include"WeArtAnalogSensorData.h"
#include"WeArtTemperature.h"
#include"WeArtTexture.h"
#include"WeArtThimbleTrackingObject.h"
#include"WeArtTrackingCalibration.h"
#include"WeArtTrackingRawData.h"
