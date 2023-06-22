#include "..\Headers\RoomAdminRequestHandler.h"

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo info)
{
    return info.requestId == CloseRoom || info.requestId == StartGame || info.requestId == GetRoomState;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo info)
{
    if (isRequestRelevant(info))
    {
        switch (info.requestId)
        {
        case CloseRoom:
            return closeRoom(info);
        case StartGame:
            return startGame(info);
        case GetRoomState:
            return getRoomState(info);
        }
    }

}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo info)
{
    CloseRoomResponse response;
    

}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo info)
{
    return RequestResult();
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo info)
{
    return RequestResult();
}
