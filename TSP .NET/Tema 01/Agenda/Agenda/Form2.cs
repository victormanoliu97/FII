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
    public partial class Form2 : Form
    {
        private readonly ContactRepository _contactRepository = new ContactRepository();
        private readonly Utils.Utils _utils = new Utils.Utils();

        private void SetContactsDetailsVisibleReadOnly(bool visible, bool readOnly)
        {
            if (nameTxtBox != null && surnameTxtBox != null && emailTxtBox != null && descriptionTxtBox != null &&
                birthDate != null && modifyBtn != null && deleteBtn != null)
            {
                nameTxtBox.Visible = visible;
                surnameTxtBox.Visible = visible;
                emailTxtBox.Visible = visible;
                descriptionTxtBox.Visible = visible;
                nameTxtBox.ReadOnly = readOnly;
                surnameTxtBox.ReadOnly = readOnly;
                emailTxtBox.ReadOnly = readOnly;
                descriptionTxtBox.ReadOnly = readOnly;
                birthDate.Enabled = !visible;
                birthDate.ShowUpDown = visible;
                birthDate.Visible = visible;
                modifyBtn.Visible = visible;
                deleteBtn.Visible = visible;
                label1.Visible = visible;
                label2.Visible = visible;
                label3.Visible = visible;
                label4.Visible = visible;
                label5.Visible = visible;
            }
        }

        private void ShowContactInformation(Contact contact)
        {
            if (contact != null)
            {
                nameTxtBox.Text = contact.FirstName;
                surnameTxtBox.Text = contact.LastName;
                emailTxtBox.Text = contact.Email;
                descriptionTxtBox.Text = contact.Description;
                birthDate.Text = contact.DateOfBirth.ToShortDateString();
            }
        }

        public Form2()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            SetContactsDetailsVisibleReadOnly(true, true);
            Contact selectedContact = (Contact) listBox1.SelectedItem;
            ShowContactInformation(selectedContact);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            List<Contact> contacts = _contactRepository.GetAllContacts();
            listBox1.Items.Clear();
            foreach (var contact in contacts)
            {
                listBox1.Items.Add(contact);
            }
        }

        private void deleteBtn_Click(object sender, EventArgs e)
        {
            Contact selectedContact = (Contact)listBox1.SelectedItem;
            var resultIndex = listBox1.FindStringExact(selectedContact.ToString());

            if (resultIndex != -1)
            {
                _contactRepository.RemoveContact(resultIndex);
                listBox1.Items.RemoveAt(resultIndex);
            }
        }

        private void modifyBtn_Click(object sender, EventArgs e)
        {
            Contact selectedContact = (Contact)listBox1.SelectedItem;
            var resultIndex = listBox1.FindStringExact(selectedContact.ToString());

            Form form3 = new Form3(selectedContact, resultIndex);
            form3.Show();
        }
    }
}
