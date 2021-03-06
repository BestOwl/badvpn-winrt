/**
* @file cryptoman.h
* @author MicroHao <microhaohao@gmail.com>
*
* @section LICENSE
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
* 3. Neither the name of the author nor the
*    names of its contributors may be used to endorse or promote products
*    derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

struct socks_crypto_info_t {
	const char key[EVP_MAX_KEY_LENGTH];
	size_t key_len;
	int iv_size;
	const EVP_CIPHER *cipher;
	const EVP_MD *dgst;
	const *password;
} ss_crypto_info;

int cryptoman_Init(char  *crypto_method_name, char *password);
int random_iv(char *iv, int size);
int encryptor_Init(EVP_CIPHER_CTX *octx, const char *iv);
int decryptor_Init(EVP_CIPHER_CTX *octx, const char *iv);
int encrypt(EVP_CIPHER_CTX *ctx, uint8_t *buf, int buf_len, uint8_t *ciphertext);
int decrypt(EVP_CIPHER_CTX *ctx, uint8_t *buf, int buf_len, uint8_t *plaintext);
void cryptor_free(EVP_CIPHER_CTX *ctx);
