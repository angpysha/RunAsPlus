#pragma once
#define cleanup() if (hToken) \
				{				\
					CloseHandle(hToken);	\
						hToken = NULL;					\
				}					\
				if (hTokenToCheck) \
				{  \
					CloseHandle(hTokenToCheck); \
					hTokenToCheck = NULL; \
				} \
				if (ERROR_SUCCESS != dwError) \
				{				\
					throw dwError;		\
				}		

#define errorReturn() dwError = GetLastError();\
					cleanup();\
					return fInAdminGroup;