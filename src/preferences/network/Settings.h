/*
 * Copyright 2004-2013 Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Andre Alves Garzia, andre@andregarzia.com
 *		Vegard Wærp, vegarwa@online.no
 */
#ifndef SETTINGS_H
#define SETTINGS_H


#include <vector>

#include <NetworkDevice.h>
#include <ObjectList.h>
#include <String.h>


class Settings {
public:
								Settings(const char* name);
	virtual						~Settings();

			void				SetIP(const BString& ip)
									{ fIP = ip; }
			void				SetGateway(const BString& ip)
									{ fGateway = ip; }
			void				SetNetmask(const BString& ip)
									{ fNetmask = ip; }
			void				SetDomain(const BString& domain)
									{ fDomain = domain; }
			void				SetAutoConfigure(bool autoConfigure)
									{ fAuto = autoConfigure; }
			void				SetDisabled(bool disabled)
									{ fDisabled = disabled; }

			const char*			IP()  { return fIP.String(); }
			const char*			Gateway()  { return fGateway.String(); }
			const char*			Netmask()  { return fNetmask.String(); }
			const char*			Name()  { return fName.String(); }
			const char*			Domain() { return fDomain.String(); }
			bool				AutoConfigure() { return fAuto; }
			bool				IsDisabled() { return fDisabled; }

			std::vector<wireless_network> WirelessNetworks();

			BObjectList<BString>& NameServers() { return fNameServers; }

			void				ReadConfiguration();

private:
			BString				fIP;
			BString				fGateway;
			BString				fNetmask;
			BString				fName;
			BString				fDomain;
			bool				fAuto;
			bool				fDisabled;
			BObjectList<BString> fNameServers;
};


#endif /* SETTINGS_H */
