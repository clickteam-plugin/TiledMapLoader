#define IDS_EXT_VERSION	5
#define EXT_VERSION "tiledmaploader #13"

class Extension {
public:

	LPRDATA rdPtr;
	LPRH rhPtr;

	Edif::Runtime Runtime;

	static const int MinimumBuild = 248;
	static const int Version = 1;

	static const int OEFLAGS = OEFLAG_VALUES | OEFLAG_RUNBEFOREFADEIN | OEFLAG_NEVERKILL;
	static const int OEPREFS = 0;

	static const int WindowProcPriority = 100;

	Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
	~Extension();

#include "RExtension.h"


	void Action(int ID, LPRDATA rdPtr, long param1, long param2);
	long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
	long Expression(int ID, LPRDATA rdPtr, long param);

	short Handle();
	short Display();

	short Pause();
	short Continue();

	bool Save(HANDLE File);
	bool Load(HANDLE File);

};
