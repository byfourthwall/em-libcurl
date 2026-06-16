#ifndef __EM_LIBCURL_CURL_MODULE_SPEC_H_
#define __EM_LIBCURL_CURL_MODULE_SPEC_H_

#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/em-libcurl.h"

module(T_curl, {
  describe("libcurl wrapper", {
    it("initializes the global curl environment", {
      CURLcode code;
      code = curl_global_init(CURL_GLOBAL_DEFAULT);
      assert_that_int(code equals to CURLE_OK);
      curl_global_cleanup();
    });

    it("creates an easy handle", {
      CURL *handle;
      int ok;
      curl_global_init(CURL_GLOBAL_DEFAULT);
      handle = curl_easy_init();
      ok     = (handle != NULL);
      assert_that(ok);
      curl_easy_cleanup(handle);
      curl_global_cleanup();
    });

    it("reports version info", {
      curl_version_info_data *ver;
      int ok;
      curl_global_init(CURL_GLOBAL_DEFAULT);
      ver = curl_version_info(CURLVERSION_NOW);
      ok  = (ver != NULL);
      assert_that(ok);
      ok = (ver->version_num > 0);
      assert_that(ok);
      curl_global_cleanup();
    });

    it("sets an option on an easy handle", {
      CURL *handle;
      CURLcode code;
      curl_global_init(CURL_GLOBAL_DEFAULT);
      handle = curl_easy_init();
      code   = curl_easy_setopt(handle, CURLOPT_URL, "https://example.com");
      assert_that_int(code equals to CURLE_OK);
      curl_easy_cleanup(handle);
      curl_global_cleanup();
    });
  });
})

#endif
