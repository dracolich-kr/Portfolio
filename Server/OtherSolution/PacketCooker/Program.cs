using System;
using System.IO;

namespace PacketCooker
{
    class Program
    {
        static void Main(string[] args)
        {
            String output_path = args[0];

            CookerEngine engine = new CookerEngine();
            engine.Work(output_path);
        }
    }
}
