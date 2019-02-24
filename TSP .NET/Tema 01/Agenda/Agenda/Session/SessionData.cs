using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace Agenda.Session
{
    public class SessionData
    {
        private readonly string _filePath = @"D:\Facultate\Anul 3\Semestrul 2\TSP.NET\Tema 01\session.json";

        private JObject ReadFlagFromFile()
        {
            var json = File.ReadAllText(_filePath);
            var deserializeObject = JObject.Parse(json);

            return deserializeObject;
        }

        public Boolean ReadFlagValue()
        {
            var isFirstRunnedValue = ReadFlagFromFile();
            return (bool) isFirstRunnedValue["isFirstRunned"];
        }

        public void SetIsFirstRunnedTrue()
        {
            var isFirstRunned = ReadFlagFromFile();

            isFirstRunned["isFirstRunned"] = true;
            var jsonToAdd = JsonConvert.SerializeObject(isFirstRunned, Formatting.Indented);
            System.IO.File.WriteAllText(_filePath, jsonToAdd);
        }

        public void SetIsFirstRunnedFalse()
        {
            var isFirstRunned = ReadFlagFromFile();

            isFirstRunned["isFirstRunned"] = false;
            var jsonToAdd = JsonConvert.SerializeObject(isFirstRunned, Formatting.Indented);
            System.IO.File.WriteAllText(_filePath, jsonToAdd);
        }
    }
}
