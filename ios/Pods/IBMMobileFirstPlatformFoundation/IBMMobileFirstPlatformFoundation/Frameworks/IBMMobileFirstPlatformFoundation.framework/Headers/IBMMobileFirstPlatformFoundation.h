/*
 *  Licensed Materials - Property of IBM
 *  5725-I43 (C) Copyright IBM Corp. 2011, 2013. All Rights Reserved.
 *  US Government Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */
//
//  IBMMobileFirstPlatformFoundation.h
//  IBMMobileFirstPlatformFoundation
//
//  Created by C A on 3/11/15.
//  Copyright (c) 2015 IBM. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for IBMMobileFirstPlatformFoundation.
FOUNDATION_EXPORT double IBMMobileFirstPlatformFoundationVersionNumber;

//! Project version string for IBMMobileFirstPlatformFoundation.
FOUNDATION_EXPORT const unsigned char IBMMobileFirstPlatformFoundationVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <IBMMobileFirstPlatformFoundation/PublicHeader.h>

#import <IBMMobileFirstPlatformFoundation/AccessToken.h>
#import <IBMMobileFirstPlatformFoundation/BaseChallengeHandler.h>
#import <IBMMobileFirstPlatformFoundation/GatewayChallengeHandler.h>
#import <IBMMobileFirstPlatformFoundation/OCLogger.h>
#import <IBMMobileFirstPlatformFoundation/OCLogger+Constants.h>
#import <IBMMobileFirstPlatformFoundation/WLAnalytics.h>
#import <IBMMobileFirstPlatformFoundation/WLAuthorizationManager.h>
#import <IBMMobileFirstPlatformFoundation/SecurityCheckChallengeHandler.h>
#import <IBMMobileFirstPlatformFoundation/WLClient.h>
#import <IBMMobileFirstPlatformFoundation/WLCookieExtractor.h>
#import <IBMMobileFirstPlatformFoundation/WLDelegate.h>
#import <IBMMobileFirstPlatformFoundation/WLDeviceAuthManager.h>
#import <IBMMobileFirstPlatformFoundation/WLFailResponse.h>
#import <IBMMobileFirstPlatformFoundation/WLProcedureInvocationData.h>
#import <IBMMobileFirstPlatformFoundation/WLProcedureInvocationResult.h>
#import <IBMMobileFirstPlatformFoundation/WLResourceRequest.h>
#import <IBMMobileFirstPlatformFoundation/WLResponse.h>
#import <IBMMobileFirstPlatformFoundation/WLResponseListener.h>
#import <IBMMobileFirstPlatformFoundation/WLSecurityUtils.h>
#import <IBMMobileFirstPlatformFoundation/WLSecurityCommonUtils.h>
#import <IBMMobileFirstPlatformFoundation/WLSecurityConstants.h>
#import <IBMMobileFirstPlatformFoundation/WLSimpleDataSharing.h>
//#import <IBMMobileFirstPlatformFoundation/WLWatchConnectivityManager.h>
//#import <IBMMobileFirstPlatformFoundation/WLCertManagerCommon.h>
