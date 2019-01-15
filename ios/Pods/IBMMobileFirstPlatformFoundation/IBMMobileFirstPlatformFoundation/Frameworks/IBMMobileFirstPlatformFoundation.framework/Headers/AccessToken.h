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

@interface AccessToken : NSObject

@property (readonly, nonatomic) NSString * value;
@property (readonly, nonatomic) NSString * scope;
@property (readonly, nonatomic) NSString * asAuthorizationRequestHeaderField;
@property (readonly, nonatomic) NSString * asFormEncodedBodyParameter;

-(id) initWithToken:(NSString*)token WithExpiration:(double)expiration ForScope:(NSString*)scope;


@end
