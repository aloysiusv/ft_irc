/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_motd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:23:13 by bbrassar          #+#    #+#             */
/*   Updated: 2022/12/12 22:51:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include "CommandMap.hpp"
#include <fstream>

void cmd_motd(CommandContext& context)
{
	context.server.sendMotd(context.client);
}
