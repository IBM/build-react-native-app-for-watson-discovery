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

#import "WLSecurityConstants.h"

@interface WLSecurityCommonUtils : NSObject

/**
 Takes an NSString and returns Base64 encoded NSData.
 @param string Input NSString
 @return Base64 encoded NSData
 @since IBM Worklight V6.2.0
 */
+ (NSData*) base64DataFromString:(NSString*) string;

+ (NSString*) _base64StringFromData:(NSData*) data
                             length:(unsigned long)length
                          isSafeUrl:(bool) isSafeUrl;

+(unsigned char *) _getNativeKeyFromHexString:(NSString *) key
                         withCorrectConversion:(BOOL) correctConversion;

+(unsigned char *) _getNativeIVFromHexString:(NSString*) iv
                       withCorrectConversion:(BOOL) correctConversion;


@end
