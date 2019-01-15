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

@interface WLSecurityConstants : NSObject

extern int const WLkChosenCipherIVSize;
extern int const WLkChosenCipherKeySize;

extern int const CURRENT_SEC_VERSION;

extern NSString *const WL_BASE64_REGEX;
extern NSString *const CIPHER_TEXT_KEY;
extern NSString *const IV_KEY;
extern NSString *const ERR_MSG_KEY;
extern NSString *const KEY_VERSION;
extern NSString *const KEY_SRC;
extern NSString *const KEY_BASE64;

extern NSString *const DEFAULT_SCOPE;

extern NSString *const SRC_OBJECTIVE_C;

extern NSString *const ENCRYPT_ERROR_FORMAT_MSG;
extern NSString *const KEYGEN_ERROR_FORMAT_MSG;
extern NSString *const DECRYPT_ERROR_FORMAT_MSG;

extern NSString *const ERROR_LABEL_KEYGEN;
extern NSString *const MISSING_OPEN_SSL_FRAMEWORK;
extern NSString *const ERROR_LABEL_ENCRYPT;
extern NSString *const ERROR_LABEL_DECRYPT;
extern NSString *const ERROR_LABEL;

extern NSString *const ERROR_MSG_INVALID_IV_LENGTH;

extern NSString *const ERROR_MSG_EMPTY_TEXT;
extern NSString *const ERROR_MSG_EMPTY_CIPHER;
extern NSString *const ERROR_MSG_EMPTY_KEY;
extern NSString *const ERROR_MSG_EMPTY_IV;
extern NSString *const ERROR_MSG_INVALID_ITERATIONS;
extern NSString *const ERROR_MSG_MISSING_OPEN_SSL_FRAMEWORK;

extern NSString *const ERROR_MSG_EMPTY_PASSWORD;
extern NSString *const ERROR_MSG_EMPTY_SALT;
extern NSString *const ERROR_MSG_KEY_DERRIVATION;
extern NSString *const ERROR_MSG_INVALID_SRC;
extern NSString *const ERROR_MSG_INVALID_VERSION;

@end
