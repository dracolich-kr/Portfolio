using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace PacketCooker
{
    public class CookerEngine
    {
        static private String NewLine = "\r\n";
        static private char[] Token = { '\t', ' ', ','};
        static private String ProtocolName = "eID";
        static private Encoding Code949 = Encoding.GetEncoding("ks_c_5601-1987");

        public CookerEngine()
        {
        }

        public void Work(String output_path)
        {
            String current_path = Directory.GetCurrentDirectory();

            SearchGenerateIdFiles("ProtocolIdRange.fbs");
            GenerateProtocolId();

            char[] token = { '\\', '/' };
            Int32 index = output_path.LastIndexOfAny(token) + 1;
            String output_dir = output_path.Substring(index, output_path.Length - index);

            Cooker cooker = new Cooker();
            cooker.Parsing("..\\", output_dir, current_path);

        }

        private void SearchGenerateIdFiles(String file_name)
        {
            String file_data = File.ReadAllText(file_name, Code949);

            Int32 start_index = file_data.IndexOf("GenerateRange");
            if (start_index == -1)
                return;

            start_index = file_data.IndexOf('{', start_index) + 1;
            if (start_index == -1)
                return;

            Int32 end_index = file_data.IndexOf('}', start_index) - 1;
            if (end_index == -1)
                return;

            String body_data = file_data.Substring(start_index, end_index - start_index);
            body_data += NewLine;

            start_index = body_data.IndexOf(NewLine) + NewLine.Length;
            end_index = body_data.IndexOf(NewLine, start_index + NewLine.Length);

            while (end_index != -1)
            {
                String line = body_data.Substring(start_index, end_index - start_index);
                String[] infos = line.Split(Token, StringSplitOptions.RemoveEmptyEntries);

                if (infos.Length == 3)
                {
                    GenerateFolders.Add(infos[0], Convert.ToInt32(infos[2]));
                }

                start_index = end_index + NewLine.Length;
                end_index = body_data.IndexOf(NewLine, start_index);
            }
        }

        private void GenerateProtocolId()
        {
            String current_path = Directory.GetCurrentDirectory();

            foreach (var folder in GenerateFolders)
            {
                String path = $"{current_path}\\{folder.Key}";
                if (Directory.Exists(path) == false)
                    continue;

                if (File.Exists($"{path}\\body.fbs") == false)
                    continue;

                var protocol_names = UpdateBodyAndGetList(path);

                String buffer = 
$@"namespace Protocol.{folder.Key};
                
enum eID : uint
{{
    None = {folder.Value}
{WriteEnumBody(protocol_names, folder.Value)}
}}
";
                File.WriteAllText($"{path}\\id.fbs", buffer);
            }
        }

        private List<String> UpdateBodyAndGetList(String path)
        {
            var protocol_names = new List<String>();

            String file_data = File.ReadAllText($"{path}\\body.fbs", Code949);

            Int32 start_index = file_data.IndexOf("table");
            if (start_index == -1)
                return protocol_names;
            Int32 end_index = file_data.IndexOf(NewLine, start_index);
            if (end_index == -1)
                return protocol_names;

            while(end_index > 0)
            {
                String temp = file_data.Substring(start_index, end_index - start_index);
                var spilts = temp.Split(Token, StringSplitOptions.RemoveEmptyEntries);

                Int32 close_index = file_data.IndexOf("}", start_index);
                if (close_index == -1)
                    break;

                Int32 id_index = file_data.IndexOf(ProtocolName, start_index);
                if(id_index != -1 || id_index < close_index)
                {
                    String name = spilts[1];
                    protocol_names.Add(name);

                    end_index = file_data.IndexOf(NewLine, id_index);
                    file_data = file_data.Remove(id_index + ProtocolName.Length, end_index - (id_index + ProtocolName.Length));
                    file_data = file_data.Insert(id_index + ProtocolName.Length, $" = {name};");
                }

                start_index = file_data.IndexOf("table", close_index);
                if (start_index == -1)
                    break;

                end_index = file_data.IndexOf(NewLine, start_index);
            }

            File.WriteAllText($"{path}\\body.fbs", file_data, Code949);

            return protocol_names;
        }

        private String WriteEnumBody(List<String> protocol_names, Int32 start_index)
        {
            if (protocol_names.Count <= 0)
                return String.Empty;

            String buffer = String.Empty;
            String last = protocol_names.Last();

            foreach(var name in protocol_names)
            {
                buffer += $"\t, {name} = {++start_index}";

                if (last != name)
                    buffer += NewLine;
            }

            return buffer;
        }

        private Dictionary<String, Int32> GenerateFolders { get; set; } = new Dictionary<String, Int32>();
    }
}