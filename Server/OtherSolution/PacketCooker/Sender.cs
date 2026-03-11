using System;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace PacketCooker
{
    public class Sender
    {
        static private String NewLine = "\r\n";
        static private char[] Token = { '\t', ' ', ',' };
        static private Encoding Code949 = Encoding.GetEncoding("ks_c_5601-1987");
        static private String NameSpaceToken = "namespace";
        private String mNameSpace = String.Empty;

        public void Write(String file_name, String output_path)
        {
            Parsing(file_name);
            WriteHeader(output_path);
            WriteBody(output_path);
        }

        private void Parsing(String file_name)
        {
            String file_data = File.ReadAllText(file_name, Code949);

            Int32 start_index = file_data.IndexOf(NameSpaceToken);
            if (start_index == -1)
                return;

            Int32 end_index = file_data.IndexOf(";", start_index);
            if (end_index == -1)
                return;

            mNameSpace = file_data.Substring(start_index + NameSpaceToken.Length, end_index - (start_index + NameSpaceToken.Length));
            mNameSpace = mNameSpace.Replace(".", "::");

            start_index = file_data.IndexOf('{', start_index) + 1;
            if (start_index == -1)
                return;

            end_index = file_data.IndexOf('}', start_index) - 1;
            if (end_index == -1)
                return;
        }

        private void WriteHeader(String file_name)
        {
            String buffer = $@"#pragma once

namespace {mNameSpace}
{{
    class Sender
    {{
    public:
        Sender(Network::SharedSession session)
            : mSession(session)
        {{}}
        virtual ~Sender() {{}}

{WriteSendFunction()}

    private:
        Network::SharedSession mSession;
    }};

}}
";
            File.WriteAllText($"{file_name}\\Sender.h", buffer);
        }

        private String WriteSendFunction()
        {
            String buffer = string.Empty;

            return buffer;
        }

        private void WriteBody(String file_name)
        {
            String buffer = $@"#include <pch.h>

namespace {mNameSpace}
{{

}}
";
            File.WriteAllText($"{file_name}\\Sender.cpp", buffer);
        }

        private String WriteFunction()
        {
            String buffer = string.Empty;

            return buffer;
        }
    }
}
