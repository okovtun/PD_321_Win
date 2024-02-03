namespace WindowsForms
{
	partial class AddAlarm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AddAlarm));
			this.dateTimePickerDate = new System.Windows.Forms.DateTimePicker();
			this.dateTimePickerTime = new System.Windows.Forms.DateTimePicker();
			this.labelFilename = new System.Windows.Forms.Label();
			this.buttonChooseFile = new System.Windows.Forms.Button();
			this.checkedListBoxDays = new System.Windows.Forms.CheckedListBox();
			this.labelBitset = new System.Windows.Forms.Label();
			this.buttonAdd = new System.Windows.Forms.Button();
			this.axWindowsMediaPlayer1 = new AxWMPLib.AxWindowsMediaPlayer();
			this.buttonCancel = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.axWindowsMediaPlayer1)).BeginInit();
			this.SuspendLayout();
			// 
			// dateTimePickerDate
			// 
			this.dateTimePickerDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
			this.dateTimePickerDate.Location = new System.Drawing.Point(13, 13);
			this.dateTimePickerDate.Name = "dateTimePickerDate";
			this.dateTimePickerDate.Size = new System.Drawing.Size(104, 20);
			this.dateTimePickerDate.TabIndex = 0;
			// 
			// dateTimePickerTime
			// 
			this.dateTimePickerTime.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
			this.dateTimePickerTime.Location = new System.Drawing.Point(124, 13);
			this.dateTimePickerTime.Name = "dateTimePickerTime";
			this.dateTimePickerTime.Size = new System.Drawing.Size(106, 20);
			this.dateTimePickerTime.TabIndex = 1;
			// 
			// labelFilename
			// 
			this.labelFilename.AutoSize = true;
			this.labelFilename.Location = new System.Drawing.Point(12, 83);
			this.labelFilename.Name = "labelFilename";
			this.labelFilename.Size = new System.Drawing.Size(71, 13);
			this.labelFilename.TabIndex = 2;
			this.labelFilename.Text = "labelFilename";
			// 
			// buttonChooseFile
			// 
			this.buttonChooseFile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.buttonChooseFile.Location = new System.Drawing.Point(13, 142);
			this.buttonChooseFile.Name = "buttonChooseFile";
			this.buttonChooseFile.Size = new System.Drawing.Size(75, 23);
			this.buttonChooseFile.TabIndex = 3;
			this.buttonChooseFile.Text = "Choose file";
			this.buttonChooseFile.UseVisualStyleBackColor = true;
			this.buttonChooseFile.Click += new System.EventHandler(this.buttonChooseFile_Click);
			// 
			// checkedListBoxDays
			// 
			this.checkedListBoxDays.CheckOnClick = true;
			this.checkedListBoxDays.ColumnWidth = 48;
			this.checkedListBoxDays.FormattingEnabled = true;
			this.checkedListBoxDays.Items.AddRange(new object[] {
            "Mon",
            "Tue",
            "Wed",
            "Thu",
            "Fri",
            "Sat",
            "Sun"});
			this.checkedListBoxDays.Location = new System.Drawing.Point(12, 43);
			this.checkedListBoxDays.MultiColumn = true;
			this.checkedListBoxDays.Name = "checkedListBoxDays";
			this.checkedListBoxDays.Size = new System.Drawing.Size(350, 19);
			this.checkedListBoxDays.TabIndex = 4;
			this.checkedListBoxDays.SelectedIndexChanged += new System.EventHandler(this.checkedListBoxDays_SelectedIndexChanged);
			// 
			// labelBitset
			// 
			this.labelBitset.AutoSize = true;
			this.labelBitset.Location = new System.Drawing.Point(209, 67);
			this.labelBitset.Name = "labelBitset";
			this.labelBitset.Size = new System.Drawing.Size(33, 13);
			this.labelBitset.TabIndex = 5;
			this.labelBitset.Text = "Bitset";
			// 
			// buttonAdd
			// 
			this.buttonAdd.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.buttonAdd.Location = new System.Drawing.Point(212, 142);
			this.buttonAdd.Name = "buttonAdd";
			this.buttonAdd.Size = new System.Drawing.Size(75, 23);
			this.buttonAdd.TabIndex = 6;
			this.buttonAdd.Text = "Add";
			this.buttonAdd.UseVisualStyleBackColor = true;
			this.buttonAdd.Click += new System.EventHandler(this.buttonAdd_Click);
			// 
			// axWindowsMediaPlayer1
			// 
			this.axWindowsMediaPlayer1.Enabled = true;
			this.axWindowsMediaPlayer1.Location = new System.Drawing.Point(137, 83);
			this.axWindowsMediaPlayer1.Name = "axWindowsMediaPlayer1";
			this.axWindowsMediaPlayer1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axWindowsMediaPlayer1.OcxState")));
			this.axWindowsMediaPlayer1.Size = new System.Drawing.Size(225, 35);
			this.axWindowsMediaPlayer1.TabIndex = 8;
			// 
			// buttonCancel
			// 
			this.buttonCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.buttonCancel.Location = new System.Drawing.Point(294, 141);
			this.buttonCancel.Name = "buttonCancel";
			this.buttonCancel.Size = new System.Drawing.Size(75, 23);
			this.buttonCancel.TabIndex = 9;
			this.buttonCancel.Text = "Cancel";
			this.buttonCancel.UseVisualStyleBackColor = true;
			this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
			// 
			// AddAlarm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(377, 177);
			this.Controls.Add(this.buttonCancel);
			this.Controls.Add(this.axWindowsMediaPlayer1);
			this.Controls.Add(this.buttonAdd);
			this.Controls.Add(this.labelBitset);
			this.Controls.Add(this.checkedListBoxDays);
			this.Controls.Add(this.buttonChooseFile);
			this.Controls.Add(this.labelFilename);
			this.Controls.Add(this.dateTimePickerTime);
			this.Controls.Add(this.dateTimePickerDate);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Name = "AddAlarm";
			this.Text = "AddAlarm";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.AddAlarm_Closing);
			((System.ComponentModel.ISupportInitialize)(this.axWindowsMediaPlayer1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.DateTimePicker dateTimePickerDate;
		private System.Windows.Forms.DateTimePicker dateTimePickerTime;
		private System.Windows.Forms.Label labelFilename;
		private System.Windows.Forms.Button buttonChooseFile;
		private System.Windows.Forms.CheckedListBox checkedListBoxDays;
		private System.Windows.Forms.Label labelBitset;
		private System.Windows.Forms.Button buttonAdd;
		private AxWMPLib.AxWindowsMediaPlayer axWindowsMediaPlayer1;
		private System.Windows.Forms.Button buttonCancel;
		//private System.Windows.Forms.FormClosingEventHandler FormClosing;
	}
}