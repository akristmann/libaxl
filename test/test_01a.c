#include <axl.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
	axlError * error = NULL;

	/* top level definitions */
	axlDoc * doc = NULL;

	/* initialize axl library */
	if (! axl_init ()) {
		printf ("Unable to initialize Axl library\n");
		return -1;
	}

	/* get current doc reference */
	doc = axl_doc_parse_from_file ("large.xml", &error);
	if (doc == NULL) {
		printf ("Unable to parse file, error was: %s\n", axl_error_get (error));
		axl_error_free (error);
		return AXL_FALSE;
	}

	/* release the document */
	axl_doc_free (doc);

	/* cleanup axl library */
	axl_end ();

	return AXL_TRUE;
}
