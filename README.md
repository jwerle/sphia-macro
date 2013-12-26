
# sphia-macro

Macros for working with Sophia DB

## Example

```c
#include "sphia-macro.h"

int
main(void) {
  char *err = NULL;

  SPHIA_DB_OPEN(env, db, "/path/to/db", SPO_CREAT|SPO_RDWR);
  SPHIA_CATCH(err, env) goto fail;

  // do whatever...

  char key[] = "key";
  char value[] = "value";
  if (-1 == sp_set(db, key, strlen(key), value, strlen(value)))
    goto fail;

  SPHIA_DESTROY(env);
  SPHIA_CATCH(err, env) goto fail;

  SPHIA_DESTROY(db);
  SPHIA_CATCH(err, db) goto fail;

  return 0;

fail:
  if (NULL == err) err = sp_error(db);
  SPHIA_FERROR(err);
  return 1;
}


```

  Also see [test.c](https://github.com/sphia/sphia-macro/blob/master/test.c).

## License


(The MIT License)

Copyright (c) 2013 Joseph Werle &lt;joseph.werle@gmail.com&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.