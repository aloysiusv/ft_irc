/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:01:48 by bbrassar          #+#    #+#             */
/*   Updated: 2022/12/02 18:04:18 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "class/ChannelManager.hpp"

ChannelManager::ChannelManager() :
	_channels()
{}

ChannelManager::~ChannelManager()
{}

ChannelManager::iterator ChannelManager::getChannel(std::string const& name)
{
	iterator it;

	for (it = this->begin(); it != this->end() && it->name != name; ++it);
	return it;
}

ChannelManager::iterator ChannelManager::addChannel(Channel const& channel)
{
	this->_channels.push_back(channel);
	return this->_channels.rbegin().base();
}

bool ChannelManager::removeChannel(std::string const& channelName)
{
	return this->removeChannel(this->getChannel(channelName));
}

bool ChannelManager::removeChannel(iterator it)
{
	if (it == this->end())
		return false;
	this->_channels.erase(it);
	return true;
}

ChannelManager::iterator ChannelManager::begin()
{
	return this->_channels.begin();
}

ChannelManager::iterator ChannelManager::end()
{
	return this->_channels.end();
}
