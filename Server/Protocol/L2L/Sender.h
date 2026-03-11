#pragma once

namespace  Protocol::L2L
{
    class Sender
    {
    public:
        Sender(Network::SharedSession session)
            : mSession(session)
        {}
        virtual ~Sender() {}



    private:
        Network::SharedSession mSession;
    };

}
