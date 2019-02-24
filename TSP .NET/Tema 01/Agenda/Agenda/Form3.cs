using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Agenda.Repository;

namespace Agenda
{
    public partial class Form3 : Form
    {
        private readonly int _index;
        private readonly ContactRepository _contactRepository = new ContactRepository();
        private readonly  Utils.Utils _utils = new Utils.Utils();

        public Form3(Contact contact, int resultIndex)
        {
            InitializeComponent();
            if (contact != null)
            {
                nameTxtBox.Text = contact.FirstName;
                surnameTxtBox.Text = contact.LastName;
                emailTxtBox.Text = contact.Email;
                descriptionTxtBox.Text = contact.Description;
                birthDate.Text = contact.DateOfBirth.ToShortDateString();
            }

            _index = resultIndex;
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void modifyBtn_Click(object sender, EventArgs e)
        {
            if (_index != -1)
            {
                Contact modifyContact = new Contact(nameTxtBox.Text, surnameTxtBox.Text,
                    emailTxtBox.Text, descriptionTxtBox.Text, birthDate.Value, _utils.CalculateAge(birthDate.Value, DateTime.Now));

                MessageBox.Show(modifyContact.ToString());

                _contactRepository.ModifyContact(_index, modifyContact);
            }
        }
    }
}
