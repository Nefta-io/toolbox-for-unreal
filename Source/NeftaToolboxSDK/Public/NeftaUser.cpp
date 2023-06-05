#include "NeftaUser.h"

bool FNeftaUser::IsValid() const
{
	return !user_token.IsEmpty();
}
