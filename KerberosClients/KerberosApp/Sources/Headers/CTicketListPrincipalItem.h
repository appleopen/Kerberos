/* $Copyright:
 *
 * Copyright 1998-2002 by the Massachusetts Institute of Technology.
 * 
 * All rights reserved.
 * 
 * Export of this software from the United States of America may require a
 * specific license from the United States Government.  It is the
 * responsibility of any person or organization contemplating export to
 * obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and distribute
 * this software and its documentation for any purpose and without fee is
 * hereby granted, provided that the above copyright notice appear in all
 * copies and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of M.I.T. not be
 * used in advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.  Furthermore if you
 * modify this software you must label your software as modified software
 * and not distribute it in such a fashion that it might be confused with
 * the original MIT software. M.I.T. makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Individual source code files are copyright MIT, Cygnus Support,
 * OpenVision, Oracle, Sun Soft, FundsXpress, and others.
 * 
 * Project Athena, Athena, Athena MUSE, Discuss, Hesiod, Kerberos, Moira,
 * and Zephyr are trademarks of the Massachusetts Institute of Technology
 * (MIT).  No commercial use of these trademarks may be made without prior
 * written permission of MIT.
 * 
 * "Commercial use" means use of a name in a product or other for-profit
 * manner.  It does NOT prevent a commercial firm from referring to the MIT
 * trademarks in order to convey information (although in doing so,
 * recognition of their trademark status should be given).
 * $
 */

/* $Header: /cvs/kfm/KerberosClients/KerberosApp/Sources/Headers/CTicketListPrincipalItem.h,v 1.8 2003/06/12 15:45:46 smcguire Exp $ */

// =================================================================================
//	CTicketListPrincipalItem.h
// =================================================================================

#pragma once

#include "CTicketListItem.h"

class CTicketListPrincipalItem : public CTicketListItem {

	public:
	
		CTicketListPrincipalItem();
		
		CTicketListPrincipalItem(
					PP_PowerPlant::LStr255 inPrincipalString,
					PP_PowerPlant::LStr255 inDisplayString,
					unsigned long inStartTime,
					unsigned long inExpirationTime,
					cc_int32 inKerberosVersion,
					UCCache inCCache,
					short inTicketValidity);
		
		virtual ~CTicketListPrincipalItem();

		
		void SetPrincipalAsActive();
		void SetPrincipalAsInactive();
		
		Boolean PrincipalIsActive();

		void SetPrincipalIsRenewable(Boolean inIsRenewable);
		Boolean IsTicketRenewable();
		
		void SetRenewAttemptHalflife(unsigned long inIsRenewable);
		unsigned long GetRenewAttemptHalflife();
		
		virtual Boolean	EquivalentItem(CTicketListItem *comparisonItem);
	
	private:
	
		Boolean mIsActive;
		Boolean mPrincipalIsRenewable;
		unsigned long mRenewAttemptHalflife;
		UCCache mCCache;
};
