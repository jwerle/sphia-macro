
#include <assert.h>
#include "sphia-macro.h"

int
main (void) {
	char *err = NULL;

	SPHIA_DB_OPEN(env, db, "./test-db", SPO_CREAT|SPO_RDWR) {

		assert(env);
		assert(db);

	} SPHIA_CATCH(err, env) {

		SPHIA_FERROR(err);

	}


	SPHIA_DESTROY(env) {

		assert(NULL == env);

		SPHIA_DESTROY(db) {

			assert(NULL == db);

		} SPHIA_CATCH(err, db) {

			SPHIA_FERROR(err);

		}
	} SPHIA_CATCH(err, env) {

		SPHIA_FERROR(err);

	}

	return 0;
}
