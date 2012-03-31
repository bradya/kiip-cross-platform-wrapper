/*-
*  Cross-Platform C++ Wrapper for Kiip
*  Designed to work with iOS and Android Kiip libraries
*  http://kiip.me
*  
*  Created by Brady Archambo (in no way affiliated with Kiip)
*
*  Find me on Twitter, twitter.com/bradyy
*
*/

#ifndef __KIIP_WRAPPER_H__
#define __KIIP_WRAPPER_H__

#if defined(ANDROID)
#include "Kiip_android.h"
#elif (defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR))
#include "Kiip_ios.h"

#else
#error
#endif


#endif // __KIIP_WRAPPER_H__
