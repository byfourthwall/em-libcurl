# em-libcurl

[![MIT License](https://img.shields.io/badge/license-MIT-yellow.svg)](./LICENSE)

emeralds wrapper for the [libcurl](https://curl.se/libcurl/) C library.

# Installation

```sh
em install https://github.com/byfourthwall/em-libcurl
```

## Prerequisites: installing libcurl

This wrapper does not ship libcurl itself; it links your system's copy, which is
already present on virtually every platform:

| Platform | Install libcurl (if missing)                      |
| -------- | ------------------------------------------------- |
| macOS    | Ships with the OS (`/usr/lib/libcurl.dylib`)      |
| Linux    | Debian/Ubuntu: `apt install libcurl4-openssl-dev` |
| Windows  | MSYS2: `pacman -S mingw-w64-x86_64-curl`          |

## Usage

```c
#include "libs/em-libcurl.h"
#include <stdio.h>

static size_t on_data(void *p, size_t s, size_t n, void *u) {
  (void)p; (void)s; (void)n; (void)u;
  return 0;
}

int main(void) {
  CURL *c;
  curl_global_init(CURL_GLOBAL_DEFAULT);
  c = curl_easy_init();
  curl_easy_setopt(c, CURLOPT_URL, "https://example.com");
  curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, on_data);
  curl_easy_perform(c);
  curl_easy_cleanup(c);
  curl_global_cleanup();
  return 0;
}
```

## Contributing

1. Fork it (<https://github.com/byfourthwall/em-libcurl/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [atha](https://github.com/Oblivious-Oblivious) - creator and maintainer
