using System;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace PacketCooker
{
    public class Cooker
    {

        public void Parsing(String output_path, String path, String last_path)
        {
            OutputPath = output_path;
            Path = path;
            LastPath = last_path;

            String[] sub_dirs = Directory.GetDirectories(LastPath);

            foreach(var dir in sub_dirs)
            {
                var cooker = new Cooker();
                String tempPath = $"{Path}\\{Cooker.GetDirName(dir)}";
                cooker.Parsing(output_path, tempPath, dir);
            }

            String[] files = Directory.GetFiles(LastPath);
            String output_full_path = $"{output_path}{Path}";

            String command = $"--cpp -o {output_full_path}";
            bool exists = false;


            ClearFile(output_full_path);

            foreach (var file_name in files)
            {
                String extension = System.IO.Path.GetExtension(file_name);
                if (extension != ".fbs")
                    continue;

                string name = System.IO.Path.GetFileName(file_name);
                if (name == "body.fbs")
                {
                    Sender sender = new Sender();
                    sender.Write(file_name, output_full_path);
                }

                command += $" {file_name}";
                exists = true;
            }

            if(exists == true)
                WriteFlatBuffer(command);
        }

        private void WriteFlatBuffer(String command)
        {
            ProcessStartInfo info = new ProcessStartInfo();
            info.FileName = "flatc.exe";
            info.Arguments = command;
            info.UseShellExecute = false;
            info.RedirectStandardOutput = true;
            info.CreateNoWindow = true;

            Process process = new Process();
            process.StartInfo = info;
            process.Start();

            while(!process.StandardOutput.EndOfStream)
            {
                Console.WriteLine(process.StandardOutput.ReadLine());
            }
        }

        public static String GetDirName(String path)
        {
            Int32 index = path.LastIndexOf("\\") + 1;
            return path.Substring(index, path.Length - index);
        }

        // 폴더내 데이터 중복을 피하기 위해 삭제
        public void ClearFile(String output_path)
        {
            if (Directory.Exists(output_path) == false)
                return;

            String[] files = Directory.GetFiles(output_path);
            foreach(var file in files)
            {
                File.Delete(file);
            }
        }


        private String OutputPath { get; set; } = String.Empty;
        private String Path { get; set; } = String.Empty;
        private String LastPath { get; set; } = String.Empty;


    }
}
