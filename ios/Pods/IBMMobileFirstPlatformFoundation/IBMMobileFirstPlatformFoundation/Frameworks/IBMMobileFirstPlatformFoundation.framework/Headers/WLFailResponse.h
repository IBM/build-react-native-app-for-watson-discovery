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
//  WLFailResponse.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 6/17/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WLResponse.h"

typedef enum {
    WLErrorCodeUnexpectedError,
    WLErrorCodeProcedureError,
    WLErrorCodeSubmitFailure
} WLClientErrorCode;

/**
 *
 * Derived from WLResponse, containing error codes and messages in addition to the status in WLResponse.
 * Contains the original response data object from the server as well.
 */
@interface WLFailResponse : WLResponse {
    WLClientErrorCode* clientErrorCode;
	NSString *errorCode;
	NSString *errorMsg;

}

/**
 * The possible errors are described in the WLErrorCode section.
 */
@property (nonatomic) WLClientErrorCode* clientErrorCode;

 @property (nonatomic) NSString* errorCode;

/**
 * An error message for the developer, which is not necessarily suitable for displaying to the end user.
 */
@property (nonatomic, strong) NSString *errorMsg;


/**
 * This method returns a string message from a WLErrorCode.
 *
 **/
+(NSString *) getErrorMessageFromCode: (WLClientErrorCode) code;

/**
 * This method returns an error message from the JSON response.
 *
 **/
+(NSString *) getErrorMessageFromJSON: (NSDictionary *) jsonResponse;

/**
 * This method returns the WLErrorCode from the JSON response.
 *
 **/
+(WLClientErrorCode) getWLErrorCodeFromJSON: (NSDictionary *) jsonResponse;

+(WLFailResponse *)createFailResponseFromResponse:(WLResponse *) wlResponse error: (NSError *)error;



@end
