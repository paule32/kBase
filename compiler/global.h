// ------------------------------------------
// (c) 2012 J. Kallup
// ------------------------------------------
#ifndef __GLOBAL_H__
#define __GLOBAL_H__

struct ODBC_GlobalDriverStruct {
	int  version;		/* Protocoll version */
	int  protocoll_type;	/* dBase, MySQL ... */
	int  protocoll_command;	/* POST,GET ... */

        QString database;
        QString sql_cmd;

        QString user_name;
        QString pass_name;

	int  session;		/* timeour ... */
	int  error_num;		/* error, ok? */
	int  body_length;	/* length of body: */
};

#endif

