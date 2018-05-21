// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_TEST_CHROMEDRIVER_NET_NET_UTIL_H_
#define CHROME_TEST_CHROMEDRIVER_NET_NET_UTIL_H_

#include <string>

class URLRequestContextGetter;

class NetAddress {
 public:
  NetAddress();  // Creates an invalid address.
  explicit NetAddress(int port);  // Host is set to localhost.
  NetAddress(const std::string& host, int port);
  ~NetAddress();

  bool IsValid() const;

  // Returns host:port.
  std::string ToString() const;

  const std::string& host() const;
  int port() const;

 private:
  std::string host_;
  int port_;
};

// Synchronously fetches data from a GET HTTP request to the given URL.
// Returns true if response is 200 OK and sets response body to |response|.
// Sets |response_code| to the response code of the fetch if there were no
// network errors, otherwise it is set to -1.
bool FetchUrl(const std::string& url,
              URLRequestContextGetter* getter,
              std::string* response,
              int* response_code);

#endif  // CHROME_TEST_CHROMEDRIVER_NET_NET_UTIL_H_
