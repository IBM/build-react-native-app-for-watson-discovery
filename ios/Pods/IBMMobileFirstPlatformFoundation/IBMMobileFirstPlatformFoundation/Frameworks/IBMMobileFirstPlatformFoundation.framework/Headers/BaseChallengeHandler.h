/**
	Licensed Materials - Property of IBM

	(C) Copyright 2015 IBM Corp.

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

//  BaseChallengeHandler.h
//  WorklightStaticLibProject
//
//  Created by Ishai Borovoy on 9/12/12.
//
//  Base class for all challenge handlers.
//

#import <Foundation/Foundation.h>
#import "WLResponse.h"

@class WLRequest;

/**
 * <code>BaseChallengeHandler</code> is a base class for all challenge-handler classes.
 */
 @interface BaseChallengeHandler : NSObject {
    @private
    NSString *handlerName;
    
    @protected
    WLRequest *activeRequest;
    NSMutableArray *waitingRequestsList;
}

@property (nonatomic, strong) NSString *handlerName;
@property (atomic, strong) WLRequest *activeRequest;
@property (atomic, strong) NSMutableArray *waitingRequestsList;

/**
 * Initializes a challenge handler with an arbitrary name.
 *
 * @param name A unique name for the challenge handler.<br />
 *        If the challenge comes from a security check, the challenge-handler name must be the name of the security check.
 */
-(id)initWithName: (NSString *)name;

/**
 * Cancels a challenge. This method informs MobileFirst Platform Foundation that the you do not intend to take any additional actions in an attempt to resolve the challenge.<br/>
 * This method returns control to MobileFirst Platform Foundation for further handling. For example, call this method when the user clicks on a cancel button.
 */
-(void) cancel;

-(void) handleChallenge: (NSDictionary *)challenge;
-(void) releaseWaitingList;
-(void) clearWaitingList;

@end
