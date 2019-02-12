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
//  WLResponse.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 3/7/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WLProcedureInvocationResult.h"

/**
 * This class contains the result of a procedure invocation. IBM MobileFirst Platform passes this class as an argument to the
 * delegate methods of <code>WLClient</code> <code>invokeProcedure</code> methods.
 */
@interface WLResponse : NSObject {
	WLProcedureInvocationResult *invocationResult;
	NSObject *invocationContext;
	NSString *responseText;
    NSDictionary *userInfoDict;
}

/**
 * Retrieves the HTTP status from the response.
 */
@property (nonatomic) NSInteger status;

/**
 * error in case of fail response
 */
@property (nonatomic) NSError* error;

/**
 * Response data from the server.
 */
@property (nonatomic, strong) WLProcedureInvocationResult *invocationResult;

/**
 * Invocation context object passed when calling <code>invokeProcedure</code>.
 */
@property (nonatomic, strong) NSObject *invocationContext;

/**
 * Original response text from the server.
 */
@property (nonatomic, strong) NSString *responseText;

/**
 *  Retrieves the headers from the response.
 */
@property (nonatomic, strong) NSDictionary* headers;

/**
 * Original response data from the server.
 */
@property (readonly) NSData* responseData;

/**
 * user info
 */
@property (nonatomic, strong) NSDictionary* userInfoDict;

/**
 * Returns the value <code>NSDictionary</code> in case the response is a JSON response, otherwise it returns the value nil.
 */
@property (readonly) NSDictionary * responseJSON;

/**
 * Returns the value <code>NSDictionary</code> in case the response is a JSON response, otherwise it returns the value nil. 
 *
 * @param NSDictionary Root of the JSON object
 *
 * @deprecated This method is deprecated. Use the responseJSON property instead.
 *
 **/
-(NSDictionary *)getResponseJson;

@end
