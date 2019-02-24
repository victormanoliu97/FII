using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Agenda.Repository;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using static Agenda.Utils.Utils;

namespace Agenda
{
    public partial class Form1 : Form
    {
        private readonly ContactRepository _contactRepository = new ContactRepository();
        private readonly Utils.Utils _util = new Utils.Utils();

        public Form1()
        {
            InitializeComponent();
        }

        private void submitBtn_Click(object sender, EventArgs e)
        {
            var name = nameTxtBox.Text;
            var surname = surnameTxtBox.Text;
            var email = emailTxtBox.Text;
            var description = descriptionTxtBox.Text;
            var birth = birthPicker.Value;
            var age = _util.CalculateAge(birth, DateTime.Now);

            if (name == String.Empty || name is string == false)
            {
                MessageBox.Show(@"First name is a mandatory field");
            }
            else if (surname == String.Empty || surname is string == false)
            {
                MessageBox.Show(@"Last Name is a mandatory field");
            }
            else if (age == 0)
            {
                MessageBox.Show(@"You can't be 0 years old !");
            }
            else
            {
                var contactToAdd = new Contact(name, surname, email, description, birth, age);

                MessageBox.Show(contactToAdd.ToString());
                _contactRepository.AddContact(contactToAdd);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
                
        }
    }
}
