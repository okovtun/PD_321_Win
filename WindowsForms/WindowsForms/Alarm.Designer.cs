namespace WindowsForms
{
	partial class Alarm
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Alarm));
			this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
			this.lblSoundFile = new System.Windows.Forms.Label();
			this.btnOK = new System.Windows.Forms.Button();
			this.btnCancel = new System.Windows.Forms.Button();
			this.btnSelectSound = new System.Windows.Forms.Button();
			this.lblCurrentDirectory = new System.Windows.Forms.Label();
			this.axWindowsMediaPlayer1 = new AxWMPLib.AxWindowsMediaPlayer();
			((System.ComponentModel.ISupportInitialize)(this.axWindowsMediaPlayer1)).BeginInit();
			this.SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this.dateTimePicker1.CalendarFont = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.dateTimePicker1.Format = System.Windows.Forms.DateTimePickerFormat.Time;
			this.dateTimePicker1.Location = new System.Drawing.Point(13, 13);
			this.dateTimePicker1.Name = "dateTimePicker1";
			this.dateTimePicker1.Size = new System.Drawing.Size(200, 20);
			this.dateTimePicker1.TabIndex = 0;
			// 
			// lblSoundFile
			// 
			this.lblSoundFile.AutoSize = true;
			this.lblSoundFile.Location = new System.Drawing.Point(13, 40);
			this.lblSoundFile.Name = "lblSoundFile";
			this.lblSoundFile.Size = new System.Drawing.Size(54, 13);
			this.lblSoundFile.TabIndex = 1;
			this.lblSoundFile.Text = "Sound file";
			// 
			// btnOK
			// 
			this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.btnOK.Location = new System.Drawing.Point(392, 119);
			this.btnOK.Name = "btnOK";
			this.btnOK.Size = new System.Drawing.Size(75, 23);
			this.btnOK.TabIndex = 2;
			this.btnOK.Text = "OK";
			this.btnOK.UseVisualStyleBackColor = true;
			// 
			// btnCancel
			// 
			this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.btnCancel.Location = new System.Drawing.Point(473, 119);
			this.btnCancel.Name = "btnCancel";
			this.btnCancel.Size = new System.Drawing.Size(75, 23);
			this.btnCancel.TabIndex = 3;
			this.btnCancel.Text = "Cancel";
			this.btnCancel.UseVisualStyleBackColor = true;
			// 
			// btnSelectSound
			// 
			this.btnSelectSound.Location = new System.Drawing.Point(16, 119);
			this.btnSelectSound.Name = "btnSelectSound";
			this.btnSelectSound.Size = new System.Drawing.Size(84, 23);
			this.btnSelectSound.TabIndex = 4;
			this.btnSelectSound.Text = "Select sound";
			this.btnSelectSound.UseVisualStyleBackColor = true;
			this.btnSelectSound.Click += new System.EventHandler(this.btnSelectSound_Click);
			// 
			// lblCurrentDirectory
			// 
			this.lblCurrentDirectory.AutoSize = true;
			this.lblCurrentDirectory.Location = new System.Drawing.Point(13, 57);
			this.lblCurrentDirectory.Name = "lblCurrentDirectory";
			this.lblCurrentDirectory.Size = new System.Drawing.Size(84, 13);
			this.lblCurrentDirectory.TabIndex = 5;
			this.lblCurrentDirectory.Text = "Current directory";
			// 
			// axWindowsMediaPlayer1
			// 
			this.axWindowsMediaPlayer1.Enabled = true;
			this.axWindowsMediaPlayer1.Location = new System.Drawing.Point(126, 57);
			this.axWindowsMediaPlayer1.Name = "axWindowsMediaPlayer1";
			this.axWindowsMediaPlayer1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axWindowsMediaPlayer1.OcxState")));
			this.axWindowsMediaPlayer1.Size = new System.Drawing.Size(252, 48);
			this.axWindowsMediaPlayer1.TabIndex = 6;
			// 
			// Alarm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(560, 154);
			this.Controls.Add(this.axWindowsMediaPlayer1);
			this.Controls.Add(this.lblCurrentDirectory);
			this.Controls.Add(this.btnSelectSound);
			this.Controls.Add(this.btnCancel);
			this.Controls.Add(this.btnOK);
			this.Controls.Add(this.lblSoundFile);
			this.Controls.Add(this.dateTimePicker1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Name = "Alarm";
			this.Text = "Alarm";
			((System.ComponentModel.ISupportInitialize)(this.axWindowsMediaPlayer1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.DateTimePicker dateTimePicker1;
		private System.Windows.Forms.Label lblSoundFile;
		private System.Windows.Forms.Button btnOK;
		private System.Windows.Forms.Button btnCancel;
		private System.Windows.Forms.Button btnSelectSound;
		private System.Windows.Forms.Label lblCurrentDirectory;
		private AxWMPLib.AxWindowsMediaPlayer axWindowsMediaPlayer1;
	}
}