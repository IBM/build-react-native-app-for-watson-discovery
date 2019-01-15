/**
	Licensed Materials - Property of IBM

	(C) Copyright 2015 IBM Corp.

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#import <Foundation/Foundation.h>
#import "WLDelegate.h"

/**
 Contains WLAnalytics methods that manage analytics logs.
 */
@interface WLAnalytics : NSObject

typedef NSString* DeviceEvent;
FOUNDATION_EXPORT DeviceEvent const LIFECYCLE;
FOUNDATION_EXPORT DeviceEvent const NETWORK;

+ (WLAnalytics *) sharedInstance;

/**
 This method adds a DeviceEvent for Analytics to collect
 @param deviceEvent the DeviceEvent to collect
 */
- (void)addDeviceEventListener:(DeviceEvent)deviceEvent;

/**
 Disable analytics from collecting the specified DeviceEvent
 @param deviceEvent the DeviceEvent to remove
 */
- (void)removeDeviceEventListener:(DeviceEvent)deviceEvent;

/**
 This method enables capturing of analytics log data
 @since IBM Worklight V6.2.0
 */
- (void) enable;

/**
 This method disables capturing of analytics log data
 @since IBM Worklight V6.2.0
 */
- (void) disable;

/**
 This method sends the log file when the log buffer exists and is not empty.
 @since IBM Worklight V6.2.0
 */
- (void) send;

/**
 This method is the same as send, with the addition of a delegate that is notified when the send request succeeds or fails.
 @param userSendAnalyticsDelegate WLDelegate that handles the result of the send request with the onSuccess and onFailure methods.
 @see send
 @since IBM MobileFirst Platform V7.0.0
 */
- (void) sendWithDelegate:(id<WLDelegate>)userSendAnalyticsDelegate;

/**
 This method logs analytics data
 Some data is already captured by the framework. To avoid collisions,
 the following keys will be excluded if logged in the metadata:
    appID
    appLabel
    appVersion
    appVersionCode
    appName
    appVersion
    deviceBrand
    deviceOSversion
    deviceOS
    deviceModel
    deviceID
    timezone
    timestamp
 @param String message to be logged
 @param metadata Dictionary containing metadata to append to the log output
 @since Worklight V6.2.0
 */
- (void) log:(NSString*)message withMetadata:(NSDictionary*)metadata;

/**
 Specify current application user.  If you want user-based analytics, you must use this method
 call.  For example, use it when the user logs in, and call the unsetUserContext method when the
 user logs out.  Or if your application supports user profiles, call this method when the user
 profile changes.
 @param user the user name of the current user.
 */
- (void)setUserContext:(NSString *)user;

/**
 Unset any user context previously set. Use this when user explicitly logs out or is no longer active.
 */
- (void)unsetUserContext;

/**
  Method Triggers Inapp Feedback mode

  This method Works only if its specific to Bluemix instance
  Triggers In app Feedback Mode and enabled the user to send the feedback to Bluemix Analytic console.

  This function will be invoked only if the cache preferences are set with ANALYTICS_URL_KEY and ANALYTICS_API_KEY.
  These properties are set only when the Mobile foundation instance belongs to Bluemix instance.

  Also this function will be invoked only if analytics module installed.
  i.e add following as pod dependency
        pod 'IBMMobileFirstPlatformFoundationAnalytics'

 */
- (void)triggerFeedbackMode;

- (void)sendFeedbackFile:(NSString*) value;

@end
