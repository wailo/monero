#pragma once

#if defined(__cplusplus)
/* #include <boost/optional.hpp> */
#include <vector>

#include "hash.h"
#include <boost/optional/optional.hpp>
#include <string>

namespace crypto {
boost::optional<crypto::hash>
hash_invoice(const std::vector<char> &invoice_data,
             const std::string &invoice_number) {

  if (invoice_data.empty()) {
    return boost::none;
  }

  // check that string is size 6
  if (invoice_number.size() != 6) {
    return boost::none;
  }

  crypto::hash payment_id;
  static_assert(sizeof(payment_id.data) / sizeof(char) == 32,
                "hash size is not of size 32");

  // Use this hash functions.
  crypto::cn_slow_hash(invoice_data.data(), invoice_data.size(), payment_id);

  // Copy invoice number into the last 6 bytes of the payment_id, converting
  // from ascii to int
  for (int i = 0; i < 6; ++i) {
    payment_id.data[26 + i] = invoice_number.at(i) - '0';
  }

  sc_reduce32((unsigned char *)payment_id.data);

  return payment_id;
}

} // namespace crypto
#endif
