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
//  WLDelegate.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 8/22/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WLResponse.h"
#import "WLFailResponse.h"

/**
 A protocol that defines methods that a delegate for the WLClient invokeProcedure method should implement, to receive notifications about the success or failure of the method call.
 */
@protocol WLDelegate <NSObject>

/**
 This method will be called upon a successful call to WLCLient invokeProcedure with the WLResponse containing the
 results from the server, along with any invocation context object and status.
 @param response contains the results from the server, along with any invocation context object and status.
 */
-(void)onSuccess:(WLResponse *)response;

/**
 This method will be called if any kind of failure occurred during the execution of WLCLient invokeProcedure.
 @param response contains the error code and error message, and optionally the results from the server, along with any invocation context object and status. 
 */
-(void)onFailure:(WLFailResponse *)response;

@end
