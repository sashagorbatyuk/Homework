   M S B A M L   `   `   `  ����  ChatClientWPF    ChatClientWPF.MainWindow   5   	   W SPresentationCore, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	     � Title$  Chat Client��5   	   $	��450��6   $	��600��6*   .��5      � $��10q�6    � ColumnDefinitions 5   
   �� 5      $	��53* �6   �� 5      $
��527* �6    � RowDefinitions 5
   
   �� 5      $
��Auto �6   �� 5      $��* �6   �� 5      $
��Auto �6   .+�5   
   �� -   5         ��Name$ DisconnectButton��5      $��
Disconnect��6+   $��266,0,160,10q�6Y   $��1��6o   �� 5   
    �� Orientation$ 
Horizontal=�6   $��0,0,0,10q�6.   $��2��6@   .+�5      �� $��Name:��6   $��Center=�6$   �� 5      -   5         ��Name$ UsernameBox��5      $	��150��6+   $	��5,0q�67   �� 5      -   5        $��Connect��5      $	��100��6=   5      �� 5   
   -   5        $ ChatBox��5      $��1��6#    �� 
IsReadOnly$
 True��60    �� TextWrapping$
 Wrap=�6B   " �� VerticalScrollBarVisibility$
 Auto=�6V   
�������	 �� SelectionBrush	 �	#FF008EFF
�������$��2��6�   
 �� SelectionTextBrush

 �����$�� ��6�   4  .System.Windows.Automation.AutomationProperties   Name$ ChatBox��6�   .��6  ��5      �� 5       �� ImageSource$ /Desktop.png��6   .��5   "   5      �� 5   
   $��2��6   $ 
Horizontal=�6"   $��0,10,0,0q�6;   $��2��6M   .+�5       �� -   5        $ 
MessageBox��5       $	��400��6*   66   �� 5!      -   5        $
��Send��5!      $	��100��67   $
��10,0q�6C   5"      �� 5#   
   $
��Left=�6   $��630,199,0,0q�6-   $��1��6B   $
 Wrap=�6O   $��TextBox��6c   $	��Top=�6r   $	��120��6�   $��1��6�   5$      5%      