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
#import "WLResponse.h"
#import "AccessToken.h"

extern NSString * const ERROR_OAUTH_PREVENT_REDIRECT;
extern NSString * const ERROR_OAUTH_CANCELED;

/**
 * This class manages the OAuth interaction between the client and the authorization server
 */
@interface WLAuthorizationManager : NSObject

/**
 * Returns the authorization server URL, if this was not set, the default MFP Authorization URL is returned
 */
@property(atomic) NSURL *authorizationServerURL;

/**
 *The login timeout, if this was not set, the default 10 seconds is used
 */
@property(atomic) NSNumber *timeOut;

/**
 * Gets the <code>WLAuthorizationManager</code> shared instance
 *
 * @return <code>WLAuthorizationManager</code> shared instance
 */
+ (WLAuthorizationManager *)sharedInstance;


/**
 * Obtains an access token for the specified MobileFirst protected resource scope.
 *
 * @param scope The protected resource scope. ToDo - document the behaviour in case of nil or empty scope
 * @param completionHandler Completion handler with response containing the access token, or error information in case of failure.
 */
- (void) obtainAccessTokenForScope:(NSString *)scope
             withCompletionHandler:(void(^) (AccessToken* accessToken, NSError* error))completionHandler;

/**
 * Check if the WLResponse contains a Gateway Challenge
 * @param wlResponse The incoming response
 */
- (BOOL)isGatewayResponse : (WLResponse *) wlResponse;

/**
 *  Logout from the specified security check.
 *
 *  @param NSString - The security check to log out from.
 *  @param completionHandler Completion handler with response containing error information in case of failure.
 */
- (void) logout:(NSString *)securityCheck
withCompletionHandler:(void(^) (NSError* error))completionHandler;

/**
 *  Login to the specified security check.
 *
 *  @param NSString - The security check to log in to.
 *  @param NSDictionary - The credentials to use for login to the security check.
 *  @param completionHandler Completion handler containing the error information in case of failure.
 */
- (void) login:(NSString *)securityCheck
withCredentials:(NSDictionary *)credentials
withCompletionHandler:(void(^)(NSError* error))completionHandler;

/**
 * Checks if the response for a request to a MobileFirst protected resource indicates that authorization is required.
 *
 * @param NSURLResponse response.
 * @return true if MobileFirst authorization is required, false otherwise.
 */
- (BOOL) isAuthorizationRequiredForResponse:(NSURLResponse *)response;

/**
 * Checks whether the response is a MobileFirst OAuth error.
 *
 * @param status HTTP status
 * @param headers <code>NSDictionary</code> of response headers
 * @return true if the response is a MobileFirst OAuth error, or false otherwise.
 */

- (BOOL) isAuthorizationRequiredForResponseWithStatus:(NSInteger)status
                                              headers:(NSDictionary *) headers;

/**
 * Returns the resource scope from a response for a request to a MobileFirst protected resource.
 *
 * @param response Response returned for the request to a protected resource.
 * @return Scope that is returned in the <code>WWW-Authenticate</code> header
 */
- (NSString *) resourceScopeFromResponse:(NSURLResponse *)response;


/**
 * Clears an invalid Access token from the WLAuthorizationManager cache
 *
 * @param AccessToken to remove
 */
- (void) clearAccessToken:(AccessToken *)accessToken;

/**
 * Sets the authorization server URL
 * If this field is not set, the default MFP Authorization server URL is used
 * @param the context root of the authorization server
 */
-(void) setAuthorizationServerURL:(NSURL *)url;

/**
 * Sets the authorization flow time out.
 * if this value is not set by user, then deault 10s is considered as the default timeout
 * @param timeout
 */
-(void) setLoginTimeOut:(NSNumber *)timeOut;
/**
 * Returns the resource scope from a response for a request to a MobileFirst protected resource.
 *
 * @param NSDictionary Response headers returned for the request to a protected resource.
 * @return Scope that is returned in the <code>WWW-Authenticate</code> header
 */
- (NSString*) resourceScopeFromResponseHeaders:(NSDictionary *)headers;

@end
