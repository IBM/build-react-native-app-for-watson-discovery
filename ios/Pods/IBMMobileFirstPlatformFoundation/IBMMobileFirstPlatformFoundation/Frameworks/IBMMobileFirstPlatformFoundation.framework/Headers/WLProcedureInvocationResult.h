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
//  WLProcedureInvocationResult.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 6/29/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class contains the result of calling a back-end service, including statuses and data items that the adapter function retrieves from the server.
 */
 __attribute__((deprecated))
@interface WLProcedureInvocationResult : NSObject {

		
	@private 
	NSMutableDictionary *response;
	NSDictionary *result;
	NSMutableArray *recordNames;
	NSArray *errors;
	NSArray *warnings;
	NSArray *info;
	NSNumber *success;
}

/**
 * This property is an NSDictionary, which represents the JSON response that the IBM MobileFirst Platform Server returns.
 *
 **/
@property (nonatomic, readonly) NSDictionary *response;


-(id)initWithInvocationResultDictionary:(NSDictionary *)theResult;

/**
 * This method returns YES if the call was successful, and NO otherwise.
 *
 **/
-(BOOL)isSuccessful;

/**
 * This method returns an NSArray of applicative error messages that the server collects during the procedure call.
 *
 **/
-(NSArray *)procedureInvocationErrors;

-(NSArray *)warnMessages;
-(NSArray *)infoMessages;
@end
