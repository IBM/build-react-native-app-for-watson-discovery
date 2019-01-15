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
//  WLProcedureInvocationData.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 3/9/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *
 * This class holds all data necessary for invoking a procedure, including:
 * <ul>
 * <li>The name of the adapter and procedure to invoke</li>
 * <li>Parameters required by the procedure</li>
 * </ul>
 */
 __attribute__((deprecated))
@interface WLProcedureInvocationData : NSObject {
	@private NSString *adapter;
	NSString *procedure;

	// Array of primitive types: (NSString, NSNumber) BOOL values should be created as
	NSArray *parameters;
	BOOL compressResponse;
}

/** 
* Specifies the parameters property.
*
* Example:
*
* 		WLProcedureInvocationData  *data = [WLProcedureInvocationData ......];
* 		NSArray *myParams = [NSArray arrayWithObjects:param1, param2, param3, nil];
* 		[data setParameters:myParams];
*
*/
// The Array should contain Objects that can be parsed via JSON. NSString and NSNumber work best.
// For Boolean values, use [NSNumber numberWithBool:]
@property (nonatomic, strong) NSArray *parameters;

@property (nonatomic, strong) NSString *adapter;

@property (nonatomic, strong) NSString *procedure;

@property (nonatomic) BOOL cacheableRequest;

@property (nonatomic) BOOL compressResponse;

-(NSDictionary *)toDictionary;

// Initializes with the adapter name and the procedure name.
/**
 * Initializes with the adapter name and the procedure name.
 *
 * @param adapter Adapter name
 * @param procedureName Adapter procedure name
 **/
-(id)initWithAdapterName:(NSString *)adapter procedureName:(NSString *)procedure;

/**
 * Initializes with the adapter name and the procedure name.
 *
 * @param theAdapter Adapter name
 * @param theProcedure Adapter procedure name
 * @param compressResponse Specifies whether or not the response from the server must be compressed
 **/
-(id)initWithAdapterName:(NSString *)theAdapter procedureName:(NSString *)theProcedure compressResponse:(BOOL)isCompressResponse;

/**
 * Specifies whether or not the responses from the server must be compressed.
 *
 * The default value is false.
 *
 * @param isCompressResponse Specifies whether or not the response from the server must be compressed.
 **/
-(void)setCompressResponse :(BOOL)isCompressResponse;

-(NSString *)getParameters;
@end
