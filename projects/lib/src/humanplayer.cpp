/*
    This file is part of Cute Chess.

    Cute Chess is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cute Chess is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Cute Chess.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "humanplayer.h"
#include "chessboard/chessboard.h"

HumanPlayer::HumanPlayer(QObject* parent)
	: ChessPlayer(parent)
{
	m_isReady = true;
}

void HumanPlayer::go()
{
	startClock();
}

void HumanPlayer::makeMove(const Chess::Move& move)
{
	Q_UNUSED(move);
}

bool HumanPlayer::supportsVariant(Chess::Variant variant) const
{
	Q_UNUSED(variant);
	return true;
}

bool HumanPlayer::isHuman() const
{
	return true;
}

void HumanPlayer::onHumanMove(const BookMove& bookMove)
{
	if (!m_timer.isActive())
		return;

	Chess::Move move = m_chessboard->moveFromBook(bookMove);
	if (m_chessboard->isLegalMove(move))
		emitMove(move);
}