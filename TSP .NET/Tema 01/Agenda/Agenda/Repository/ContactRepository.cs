using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace Agenda.Repository
{
    [Serializable]
    public class ContactRepository
    {
        private const String FilePath = @"D:\Facultate\Anul 3\Semestrul 2\TSP.NET\Tema 01\contacts.json";

        public void AddContact(Contact newContact)
        {
            var initialJson = File.ReadAllText(FilePath);
            var array = JArray.Parse(initialJson);

            var itemToAdd = new JObject
            {
                ["FirstName"] = newContact.FirstName,
                ["LastName"] = newContact.LastName,
                ["Email"] = newContact.Email,
                ["Description"] = newContact.Description,
                ["DateOfBirth"] = newContact.DateOfBirth,
                ["Age"] = newContact.Age
            };

            array.Add(itemToAdd);

            var jsonToAdd = JsonConvert.SerializeObject(array, Formatting.Indented);

            System.IO.File.WriteAllText(FilePath, jsonToAdd);

        }

        public List<Contact> GetAllContacts()
        {
            var json = File.ReadAllText(FilePath);
            var contactsList = JsonConvert.DeserializeObject<List<Contact>>(json);

            return contactsList;
        }

        public void RemoveContact(int index)
        {
            var initialJson = File.ReadAllText(FilePath);
            var array = JArray.Parse(initialJson);

            array.RemoveAt(index);

            var jsonToAdd = JsonConvert.SerializeObject(array, Formatting.Indented);

            System.IO.File.WriteAllText(FilePath, jsonToAdd);
        }

        public void ModifyContact(int index, Contact contact)
        {
            var initialJson = File.ReadAllText(FilePath);
            var array = JArray.Parse(initialJson);

            var foundElement = array.ElementAt(index);

            foundElement["FirstName"] = contact.FirstName;
            foundElement["LastName"] = contact.LastName;
            foundElement["Email"] = contact.Email;
            foundElement["Description"] = contact.Description;
            foundElement["DateOfBirth"] = contact.DateOfBirth;
            foundElement["Age"] = contact.Age;

            if (foundElement["FirstName"].ToString() != contact.FirstName ||
                foundElement["LastName"].ToString() != contact.LastName ||
                foundElement["Email"].ToString() != contact.Email ||
                foundElement["Description"].ToString() != contact.Description ||
                foundElement["DateOfBirth"].ToString() != contact.DateOfBirth.ToString() ||
                foundElement["Age"].ToString() == contact.Age.ToString())
            {

                var jsonToAdd = JsonConvert.SerializeObject(array, Formatting.Indented);

                System.IO.File.WriteAllText(FilePath, jsonToAdd);
            }

        }
    }
}
