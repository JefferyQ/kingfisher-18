
#define __section(s) __attribute__((__section__(s)))
#define SECTION_INIT_TEXT __section("init.text")
#define SECTION_INIT_DATA __section("init.data")
