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
//  WLDeviceAuthManager.h
//  WorklightStaticLibProject
//

#import <Foundation/Foundation.h>
//#import <CommonCrypto/CommonDigest.h>

// TO DO : check if this class should be visible or not
@interface WLDeviceAuthManager : NSObject

/*
 * Get the DeviceAuthManager singleton instance 
 */
+ (WLDeviceAuthManager *) sharedInstance;


//Call this initializer only
-(WLDeviceAuthManager *) init;
-(NSString *) createUUID;
-(NSString *) getWLUniqueDeviceId;
-(NSDictionary *) getDeviceData;
-(void) overrideDeviceID : (NSString*) uuid;




@end

