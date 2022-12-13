/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quit.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:50:33 by bbrassar          #+#    #+#             */
/*   Updated: 2022/12/13 03:08:12 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include "Channel.hpp"
#include "CommandMap.hpp"
#include <set>

void cmd_quit(CommandContext& context)
{
	CommandContext::ArgumentList& args = context.args;
	Client& client = context.client;
	Server& server = context.server;
	std::string const prefix = client.asPrefix();
	Client::ChannelList::iterator chanIt;
	Channel::ClientList::iterator clientIt;
	std::set< Client* > recipients;
	std::set< Client* >::iterator recipIt;
	std::string reason;

	if (!args.empty())
		reason = args[0];

	for (chanIt = client.channels.begin(); chanIt != client.channels.end(); ++chanIt)
	{
		(*chanIt)->removeClient(client);
		if ((*chanIt)->empty())
			server.channelManager.removeChannel((*chanIt)->name);
		else
			for (clientIt = (*chanIt)->allClients.begin(); clientIt != (*chanIt)->allClients.end(); ++clientIt)
				recipients.insert(clientIt->client);
	}
	for (recipIt = recipients.begin(); recipIt != recipients.end(); ++recipIt)
		(*recipIt)->send(prefix + " QUIT :Quit: " + reason);
	client.send("ERROR :buh-bye ;D");
	client.shouldClose = true;
}
