#pragma once

#include <map>
#include <string>

#include <dory/memstore/store.hpp>
#include <dory/shared/pointer-wrapper.hpp>

#include <dory/third-party/dilithium/api.h>

namespace dory::crypto::asymmetric::dilithium {

[[maybe_unused]] static unsigned int constexpr SignatureLength =
    pqcrystals_dilithium2_avx2_BYTES;
[[maybe_unused]] static unsigned int constexpr PublicKeyLength =
    pqcrystals_dilithium2_avx2_PUBLICKEYBYTES;
[[maybe_unused]] static unsigned int constexpr SecretKeyLength =
    pqcrystals_dilithium2_avx2_SECRETKEYBYTES;

using pub_key = deleted_unique_ptr<unsigned char>;

/**
 * Initializes this lib and creates a local keypair
 **/
void init();

/**
 * Publishes the public part of the local keypair under the key `mem_key` to
 * the central registry
 **/
void publish_pub_key(std::string const& mem_key);

/**
 * Publishes the public part of the local keypair under the key `mem_key` to
 * the thread-safe map;
 **/
void publish_pub_key_nostore(std::string const& mem_key);

/**
 * Gets a public key from the central registry stored under the key `mem_key`
 *
 * @throw std::runtime_error if no public key is associated under `mem_key`
 **/
pub_key get_public_key(std::string const& mem_key);

/**
 * Gets a public key from the thread-safe map stored under the key `mem_key`
 *
 * @throw std::runtime_error if no public key is associated under `mem_key`
 **/
pub_key get_public_key_nostore(std::string const& mem_key);

/**
 * Gets all public keys given the prefix and the remote ids
 * Keys are looked up in the central registry using "<prefix><remote_id>"
 **/
std::map<int, pub_key> get_public_keys(std::string const& prefix,
                                       std::vector<int> const& remote_ids);

/**
 * Signs the provided message with the private key of the local keypair. The
 * signature is stored in the memory pointed to by sig.
 *
 * @param sig: pointer where to store the signature
 * @param msg: pointer to the message to sign
 * @param msg_len: length of the message
 *
 **/
int sign(unsigned char* sig, unsigned char const* msg, uint64_t msg_len);

/**
 * Verifies that the signature of msg was created with the secret key matching
 * the public key `pk`.
 *
 * @param sig: pointer to the signature
 * @param msg: pointer to the message
 * @param msg_len: length of the message
 * @param pk: pointer to the pubic key
 *
 * @returns boolean indicating the success of the verification
 **/
bool verify(unsigned char const* sig, unsigned char const* msg,
            uint64_t msg_len, pub_key const& pk);

}  // namespace dory::crypto::asymmetric::dilithium
