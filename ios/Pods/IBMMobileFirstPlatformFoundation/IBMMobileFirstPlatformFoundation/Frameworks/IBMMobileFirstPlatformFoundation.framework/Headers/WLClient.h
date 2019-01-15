/**
	Licensed Materials - Property of IBM

	(C) Copyright 2015 IBM Corp.

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

//
//  WLClient.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 3/4/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WLDelegate.h"
#import "BaseChallengeHandler.h"

@class WLCookieExtractor;
@class WLRequest;
@class WLProcedureInvocationData;
@class WLEventTransmissionPolicy;

extern NSString * const WL_DEFAULT_ACCESS_TOKEN_SCOPE;

extern NSString * const WLClientErrorDomain;

enum {
    WLClientErrorInternalError = 1,
    WLClientErrorUnresponsiveHost = 2,
    WLClientErrorRequestTimeout = 3,
    WLClientErrorServerError = 4,
    WLClientErrorAuthenticationFailure = 5
};

@protocol WLDevice;


/**
 * This singleton class exposes methods that you use to communicate with the IBM MobileFirst Platform Server.
 */
@interface WLClient : NSObject {
    
@private	
  
    //Challenge handlers
    NSMutableDictionary *challengeHandlers;
	
    
    BOOL isInitialized;
}


extern NSMutableDictionary *piggyBackData;

/**
 * Sets an authentication handler that WLClient can use for authentication-related tasks. 
 * This method must be called for WLClient to be able to access protected resources in the IBM MobileFirst Platform server.
 */
@property (nonatomic) BOOL isInitialized;

@property (readwrite) NSInteger interval;

@property (readwrite, strong) NSTimer *timer;

@property (nonatomic) BOOL isResumed;

@property (nonatomic) BOOL isRequestFailed;

/**
 * This method returns the shared instance of <code>WLClient</code>.
 * @return <code>WLClient</code>
 */
+ (WLClient *) sharedInstance;

/**
 *
 * Retrieves the shared cookie storage that is used by the framework when communicating with the server.
 *
 * @return The cookie storage object
 *
 */
-(NSHTTPCookieStorage*)HTTPCookieStorage;


/**
 * This method uses the connection properties and the application ID from the worklight.plist file to initialize communication with the IBM MobileFirst Platform Server.
 * The server checks the validity of the application version.
 *
 * If the server returns a successful response, the <code>onSuccess</code> method is called. If an error occurs, the <code>onFailure</code> method is called.
 * @note This method must be called before any other WLClient method that calls the server, such as <code>logActivity</code> and <code>invokeProcedure.</code>
 * @param delegate A class that conforms to the WLDelegate protocol.
 */
-(void) wlConnectWithDelegate:(id <WLDelegate>)delegate __deprecated;

/**
 * This method uses the connection properties and the application ID from the worklight.plist file to initialize communication with the IBM MobileFirst Platform Server.
 * The server checks the validity of the application version.
 * This method accepts a "timeout" key in its options parameter -  (NSNumber) Number of milliseconds to wait for the server response before the request times out.
 *
 * If the server returns a successful response, the <code>onSuccess</code> method is called. If an error occurs, the <code>onFailure</code> method is called.
 * @note This method must be called before any other WLClient method that calls the server, such as <code>logActivity</code> and <code>invokeProcedure.</code>
 * @param delegate A class that conforms to the WLDelegate protocol.
 * @param options Optional, can be nil. Used to set the timeout while connecting to the server and/or to set the application userId which is used by Push service. In this dictionary the user puts key "timeout" (milliseconds) to set the timeout or the key "appUserId" (NSString) to set the application UserId.
 */
-(void) wlConnectWithDelegate:(id <WLDelegate>)delegate options:(NSDictionary *)options __deprecated;

/**
 *  This method uses <code>NSURLConnection</code> to execute the provided <code>NSURLRequest</code>.
 *
 *  @param request <code>NSURLRequest</code> object
 *
 *  @param delegate
 *  An object that conforms to the <code>NSURLSessionDataDelegate</code> or <code>NSURLSessionTaskDelegate</code> protocol.
 *
 */
-(void) sendUrlRequest:(NSURLRequest *)request delegate:(id)delegate NS_SWIFT_NAME(sendUrlRequest(_:));

/**
 *  This method uses <code>NSURLConnection</code> to execute the provided <code>NSURLRequest</code>.
 *
 *  @param request <code>NSURLRequest</code> object
 *
 *  @param delegate
 *  An object that conforms to the <code>NSURLSessionDataDelegate</code> or <code>NSURLSessionTaskDelegate</code> protocol.
 * @param responseQueue
 *  An callback queue of type dispatch_queue_t
 *
 */
-(void) sendUrlRequest:(NSURLRequest *)request delegate:(id)delegate responseQueue:(dispatch_queue_t)responseQueue NS_SWIFT_NAME(sendUrlRequest(_:));
;



-(void) invokeProcedure:(WLProcedureInvocationData *)invocationData withDelegate:(id <WLDelegate>)delegate;

/**
 * This method is similar to invokeProcedure:invocationData:withDelegate, with an additional options parameter to provide more data for this procedure call.
 *
 * @param invocationData The invocation data for the procedure call.
 * @param delegate The delegate object that is used for the onSuccess and onFailure callback methods.
 * @param options A map with the following keys and values:
 *
 * - timeout – NSNumber:
 * The time, in milliseconds, for this invokeProcedure to wait before the request fails with WLErrorCodeRequestTimeout. The default timeout is 10 seconds. To disable the timeout, set this parameter to 0.
 * - invocationContext:
 * An object that is returned with WLResponse to the delegate methods. You can use this object to distinguish different invokeProcedure calls.
 *
 */

-(void) invokeProcedure:(WLProcedureInvocationData *)invocationData withDelegate:(id <WLDelegate>)delegate options:(NSDictionary *)options;

/**
 * You can use this method to register a challenge handler, which is a class that inherits either from GatewayChallengeHandler or SecurityCheckChallengeHandler.
 *
 * @param challengeHandler The challenge handler to register.
 */
-(void) registerChallengeHandler: (BaseChallengeHandler *) challengeHandler NS_SWIFT_NAME(registerChallengeHandler(_:));

/**
 * You use this method to add a global header, which is sent on each request.
 * Each WlRequest instance will use this header as an HTTP header.
 *
 * @param headerName The header name/key.
 * @param value The header value.
 */
-(void) addGlobalHeader: (NSString *) headerName headerValue:(NSString *)value;

/**
 * You use this method to remove a global header, which is no longer sent with each request.
 *
 * @param headerName The header name to be removed.
 */
-(void) removeGlobalHeader: (NSString *) headerName;

/**
 * Get a global header.
 */
-(NSDictionary *) getGlobalHeaders;


/**
 * Get challenge handler by realm key
 */
-(BaseChallengeHandler *) getChallengeHandlerBySecurityCheck: (NSString *) securityCheck;


-(NSDictionary *) getAllChallengeHandlers;

/**
 * This method sets the interval, in seconds, at which the client (device) sends a heartbeat signal to the server. 
 *
 * You use the heartbeat signal to prevent a session with the server from timing out because of inactivity. Typically, the heartbeat interval has a value that is less than the server session timeout.The server session timeout is defined in the worklight.properties file. By default, the value of the heartbeat interval is set to 420 seconds (7 minutes).
 * To disable the heartbeat signal, set a value that is less than, or equal to zero.
 *
 * @note The client sends a heartbeat signal to the server only when the application is in the foreground. When the application is sent to the background, the client stops sending heartbeat signals. The client resumes sending heartbeat signals when the application is brought to the foreground again.
 *
 * @param val The interval, in seconds, at which the heartbeat signal is sent to the server.
 */
-(void) setHeartBeatInterval :(NSInteger)val;


/**
 * Sets the IBM MobileFirst Platform server URL to the specified URL.
 * 
 * Changes the IBM MobileFirst Platform server URL to the new URL and cleans the HTTP client context.
 * After calling this method, the application is not logged in to any server.
 * 
 * Notes:
 * <ul>
 * <li>The responsibility for checking the validity of the URL is on the developer.</li>
 * <li>For hybrid applications: This call does not clean the HTTP client context saved in JavaScript.
 * For hybrid applications, it is recommended to set the server URL by using the following JavaScript function: <code>WL.App.setServerUrl</code>.</li>
 * </ul>
 *
 * Example:
 * 
 *		[[WLClient sharedInstance] setServerUrl:[NSURL URLWithString:@"http://9.148.23.88:10080/context"]];
 *
 * @param url The URL of the new server, including protocol, IP, port, and context.
 *
 */
- (void) setServerUrl: (NSURL*) url;


/*
 *Sets the Device ID MobileFirst SDK
 */
-(void) setDeviceID : (NSString*) uuid;

/**
 * Returns the current IBM MobileFirst Platform server URL.
 *
 * @return IBM MobileFirst Platform server URL
 */
- (NSURL*) serverUrl;

/**
 * Pins the host X509 certificate public key to the client application. Secured calls to the pinned remote host will be checked for a public key match. Secured calls to other hosts containing other certificates will be rejected. Some mobile operating systems might cache the certificate validation check results. Your app must call the certificate pinning method before making a secured request. Calling this method a second time overrides any previous pinning operation.
 * @param certificateFilename the name of the certificate file
 **/
-(void) pinTrustedCertificatePublicKeyFromFile:(NSString*) certificateFilename;

/**
 * Pins a list of host X509 certificates with public key to the client application. Secured calls to the all pinned remote host will be checked for a public key match. Secured calls to other hosts containing other certificates not pinned with app will be rejected. Some mobile operating systems might cache the certificate validation check results. Your app must call the certificate pinning method before making a secured request. Calling this method a second time overrides any previous pinning operation.
 * @param certificateFilenames the list conatining names of the certificate files
 **/
-(void) pinTrustedCertificatePublicKeyFromFiles:(NSArray*) certificateFilenames;

/**
 * Sets the display name of the device. The display name is stored in the MobileFirst Server registration data.
 *
 * @param deviceDisplayName The device display name to set.
 * @param completionHandler A completion-handler callback function.
 */
-(void) setDeviceDisplayName:(NSString*)deviceDisplayName WithCompletionHandler:(void(^)(NSError* error))completionHandler;

/**
 * Gets the display name of the device. The display name is retrieved from the MobileFirst Server registration data.
 *
 * @param completionHandler A completion-handler callback function. In the case of a successful completion, the display name
 *                          of the device is returned in the completion handler's <code>deviceDisplayName</code> parameter.
 */
-(void) getDeviceDisplayNameWithCompletionHandler:(void(^)(NSString *deviceDisplayName , NSError *error))completionHandler;

/**
 * Specifies default request time out.
 */
@property (readwrite) NSTimeInterval defaultRequestTimeoutInterval;

@end

@interface IBMMobileFirstPlatformFoundationHelper : NSObject

// TO DO : check if this should be visible or not
/*
 * Returns the current <em>IBMMobileFirstPlatformFoundation<em> version
 */
+(NSString*) version;

@end
