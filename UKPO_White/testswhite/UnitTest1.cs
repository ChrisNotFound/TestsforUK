using System;
using System.Collections.Generic;
using System.Linq;

using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using TestStack.White;
using TestStack.White.UIItems;
using TestStack.White.UIItems.Finders;
using TestStack.White.UIItems.MenuItems;
using TestStack.White.UIItems.ListBoxItems;
using TestStack.White.UIItems.TreeItems;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems.TabItems;
using TestStack.White.UIItems.ListViewItems;
using TestStack.White.UIItems.WindowStripControls;


namespace testswhite
{
    [TestClass]
    public class UnitTest1
    {
        Application app;
        Window window;

        [TestInitialize]
        public void InitializeApplication()
        {
            app = Application.Launch("..\\..\\..\\Debug\\UKPO_White.exe");
            window = app.GetWindow("Поиск минимального пути в графе");
        }

        [TestMethod]
        public void TestMethodCancel()
        {
            var tbX1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox1"));
            var tbY1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox2"));
            var tbX2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox3"));
            var tbY2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox4"));
            tbX1.Text = "2";
            tbY1.Text = "4";
            tbX2.Text = "19";
            tbY2.Text = "7";
            var butt = window.Get<Button>(SearchCriteria.ByAutomationId("button1"));
            butt.Click();
            var leb = window.Get<Label>(SearchCriteria.ByAutomationId("label6"));
            Assert.AreEqual("Путь ещё не найден", leb.Text);
            window.Close();
        }

        [TestMethod]
        public void TestMethodFindRoute()
        {
            var tbX1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox1"));
            var tbY1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox2"));
            var tbX2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox3"));
            var tbY2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox4"));
            tbX1.Text ="2";
            tbY1.Text = "4";
            tbX2.Text = "19";
            tbY2.Text = "7";
            var butt = window.Get<Button>(SearchCriteria.ByAutomationId("button2"));
            butt.Click();
            var leb = window.Get<Label>(SearchCriteria.ByAutomationId("label6"));
            Assert.AreEqual("00000000000010011", leb.Text);
            window.Close();
        }
        

        [TestMethod]
        public void TestMethodEnterChar()
        {
            var tbX1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox1"));
            var tbY1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox2"));
            var tbX2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox3"));
            var tbY2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox4"));
            tbX1.Text = "fds";
            tbY1.Text = "dsf";
            tbX2.Text = "dsf";
            tbY2.Text = "etfdh";
            var butt = window.Get<Button>(SearchCriteria.ByAutomationId("button2"));
            butt.Click();
            var leb = window.Get<Label>(SearchCriteria.ByAutomationId("label6"));
            Assert.AreEqual("невозможно найти путь, проверьте входные данные!", leb.Text);
            window.Close();
        }
        [TestMethod]
        public void TestMethodEnterOne()
        {
            var tbX1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox1"));
            var tbY1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox2"));
            var tbX2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox3"));
            var tbY2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox4"));
            tbX1.Text = "545";
            var butt = window.Get<Button>(SearchCriteria.ByAutomationId("button2"));
            butt.Click();
            var leb = window.Get<Label>(SearchCriteria.ByAutomationId("label6"));
            Assert.AreEqual("невозможно найти путь, проверьте входные данные!", leb.Text);
            window.Close();
        }
        [TestMethod]
        public void TestMethodTwo()
        {
            var tbX1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox1"));
            var tbY1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox2"));
            var tbX2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox3"));
            var tbY2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox4"));
            tbX1.Text = "4";
            tbY1.Text = "6";
            var butt = window.Get<Button>(SearchCriteria.ByAutomationId("button2"));
            butt.Click();
            var leb = window.Get<Label>(SearchCriteria.ByAutomationId("label6"));
            Assert.AreEqual("невозможно найти путь, проверьте входные данные!", leb.Text);
            window.Close();
        }
        [TestMethod]
        public void TestMethodThree()
        {
            var tbX1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox1"));
            var tbY1 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox2"));
            var tbX2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox3"));
            var tbY2 = window.Get<TextBox>(SearchCriteria.ByAutomationId("textBox4"));
            tbX1.Text = "6";
            tbY1.Text = "6";
            tbX2.Text = "19";
            var butt = window.Get<Button>(SearchCriteria.ByAutomationId("button2"));
            butt.Click();
            var leb = window.Get<Label>(SearchCriteria.ByAutomationId("label6"));
            Assert.AreEqual("невозможно найти путь, проверьте входные данные!", leb.Text);
            window.Close();
        }
    }
}
