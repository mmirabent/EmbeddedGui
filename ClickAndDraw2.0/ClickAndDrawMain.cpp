/***************************************************************
 * Name:      ClickAndDrawMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-02-23
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#include "ClickAndDrawMain.h"
#include <wx/msgdlg.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dc.h>
#include <wx/panel.h>
#include <wx/clrpicker.h>
#include <wx/choice.h>
#include <wx/window.h>
#include <wx/image.h>
#include <wx/bitmap.h>

//(*InternalHeaders(ClickAndDrawFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ClickAndDrawFrame)
const long ClickAndDrawFrame::ID_PANEL1 = wxNewId();
const long ClickAndDrawFrame::ID_COLOURPICKERCTRL1 = wxNewId();
const long ClickAndDrawFrame::ID_CHOICE1 = wxNewId();
const long ClickAndDrawFrame::ID_STATICTEXT1 = wxNewId();
const long ClickAndDrawFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long ClickAndDrawFrame::ID_STATICTEXT2 = wxNewId();
const long ClickAndDrawFrame::ID_FILEPICKERCTRL2 = wxNewId();
const long ClickAndDrawFrame::ID_STATICTEXT3 = wxNewId();
const long ClickAndDrawFrame::ID_FILEPICKERCTRL3 = wxNewId();
const long ClickAndDrawFrame::idMenuQuit = wxNewId();
const long ClickAndDrawFrame::idMenuAbout = wxNewId();
const long ClickAndDrawFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ClickAndDrawFrame,wxFrame)
    //(*EventTable(ClickAndDrawFrame)
    //*)
END_EVENT_TABLE()

ClickAndDrawFrame::ClickAndDrawFrame(wxWindow* parent,wxWindowID id)
{
    // Initialize variables
    drawPoints = new std::vector<wxPoint>();
    bitmap = new wxBitmap();

    //(*Initialize(ClickAndDrawFrame)
    wxMenuItem* MenuItem2;
    wxBoxSizer* VerticalSizer;
    wxMenuItem* MenuItem1;
    wxBoxSizer* HorizontalSizer;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    HorizontalSizer = new wxBoxSizer(wxHORIZONTAL);
    DrawPanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    DrawPanel->SetMinSize(wxSize(400,500));
    DrawPanel->SetBackgroundColour(wxColour(255,255,255));
    HorizontalSizer->Add(DrawPanel, 1, wxALL|wxEXPAND, 5);
    VerticalSizer = new wxBoxSizer(wxVERTICAL);
    ColorPicker = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    VerticalSizer->Add(ColorPicker, 1, wxALL|wxEXPAND, 5);
    ThicknessPicker = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    ThicknessPicker->SetSelection( ThicknessPicker->Append(_("1")) );
    ThicknessPicker->Append(_("2"));
    ThicknessPicker->Append(_("5"));
    ThicknessPicker->Append(_("10"));
    ThicknessPicker->Append(_("20"));
    VerticalSizer->Add(ThicknessPicker, 1, wxALL|wxEXPAND, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Save bitmap"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapFilePicker = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, _("Please choose where to save the drawing"), _T("Bitmap files (*.bmp)|*.bmp"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    BoxSizer1->Add(BitmapFilePicker, 0, wxALL|wxEXPAND, 5);
    VerticalSizer->Add(BoxSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Save Points"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SavePointsFilePicker = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL2, wxEmptyString, wxEmptyString, _T("CAD Points File (*.dd)|*.dd"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
    BoxSizer2->Add(SavePointsFilePicker, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VerticalSizer->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("LoadPoints"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LoadPointsFilePicker = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL3, wxEmptyString, wxEmptyString, _T("CAD Points File (*.dd)|*.dd"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL3"));
    BoxSizer3->Add(LoadPointsFilePicker, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    VerticalSizer->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    HorizontalSizer->Add(VerticalSizer, 0, wxALL|wxALIGN_TOP, 5);
    SetSizer(HorizontalSizer);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    HorizontalSizer->Fit(this);
    HorizontalSizer->SetSizeHints(this);

    DrawPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ClickAndDrawFrame::OnDrawPanelPaint,0,this);
    DrawPanel->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ClickAndDrawFrame::OnDrawPanelLeftDown,0,this);
    DrawPanel->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&ClickAndDrawFrame::OnDrawPanelLeftDoubleClick,0,this);
    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&ClickAndDrawFrame::OnFilePickerFileChanged);
    Connect(ID_FILEPICKERCTRL2,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&ClickAndDrawFrame::OnSavePointsFilePickerFileChanged);
    Connect(ID_FILEPICKERCTRL3,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&ClickAndDrawFrame::OnLoadPointsFilePickerFileChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClickAndDrawFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClickAndDrawFrame::OnAbout);
    //*)

    BitmapFilePicker->SetLabel(wxT("Save"));

    // Initial mode is color select mode
    changeMode(ColorSelectMode);
}

ClickAndDrawFrame::~ClickAndDrawFrame()
{
    //(*Destroy(ClickAndDrawFrame)
    //*)
}

void ClickAndDrawFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ClickAndDrawFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ClickAndDrawFrame::OnDrawPanelLeftDown(wxMouseEvent& event)
{
    // If we are in draw mode, ignore single clicks
    if(mode == DrawMode)
    {
        event.Skip(); // Documentation recommended
        return;
    }

    // If we were in color select mode, change the mode to clickmode
    if(mode == ColorSelectMode)
    {
        changeMode(ClickMode);
    }

    // Get the mouse position and push it onto the end of the vector
    wxPoint position = event.GetPosition();
    drawPoints->push_back(position);

    // Recommended by the wxMouseEvent documentation
    event.Skip();
}

void ClickAndDrawFrame::OnDrawPanelLeftDoubleClick(wxMouseEvent& event)
{

    switch(mode)
    {

    case ClickMode:
        changeMode(DrawMode);
        break;

    case DrawMode:
        changeMode(ColorSelectMode);
        break;

    case ColorSelectMode:
        // Do nothing
        break;
    }
}

// This event makes sure to paint the panel again whenever it's needed and we are in the DrawMode
void ClickAndDrawFrame::OnDrawPanelPaint(wxPaintEvent& event)
{
    if(mode == DrawMode)
    {

        // Draw the lines
        wxPaintDC dc(DrawPanel);
        dc.SetPen(*pen);
        dc.DrawLines(drawPoints->size(), drawPoints->data());

        // Prepare to save the drawing to a bitmap
        int width, height;
        DrawPanel->GetSize(&width, &height);
        bitmap = new wxBitmap(width, height);

        // Copy the PaintDC contents to a bitmap throuth a MemoryDC
        wxMemoryDC memdc(*bitmap);
        memdc.Blit(0,0,width,height,&dc,0,0);
        memdc.SelectObject(wxNullBitmap);

    }
}

void ClickAndDrawFrame::changeMode(Modes NewMode)
{
    mode = NewMode;

    switch(NewMode)
    {
    case ColorSelectMode:
        // Clear the draw points
        drawPoints->clear();

        // Enable the color controls and disable the file picker
        ColorPicker->Enable();
        ThicknessPicker->Enable();
        BitmapFilePicker->Disable();
        SavePointsFilePicker->Disable(); // There is nothing to save yet
        LoadPointsFilePicker->Enable();

        // Refresh the draw panel
        DrawPanel->Refresh();

        // Update the status bar
        StatusBar1->SetStatusText(wxT("Color Selection Mode"));
        break;

    case ClickMode:
        // Disable color selection controls and the file picker
        ColorPicker->Disable();
        ThicknessPicker->Disable();
        BitmapFilePicker->Disable();
        SavePointsFilePicker->Disable();
        LoadPointsFilePicker->Disable();

        // Update the status bar
        StatusBar1->SetStatusText(wxT("Drawing Mode"));
        break;

    case DrawMode:
        // Get the chosen color and line thickness
        wxColor  color           = ColorPicker->GetColour();
        wxString thicknessString = ThicknessPicker->GetString(ThicknessPicker->GetSelection());
        int thickness = wxAtoi(thicknessString);

        pen = new wxPen(color, thickness);

        DrawPanel->Refresh();

        BitmapFilePicker->Enable();
        SavePointsFilePicker->Enable();

        StatusBar1->SetStatusText(wxT("Viewing Mode"));
        break;
    }
}

void ClickAndDrawFrame::OnFilePickerFileChanged(wxFileDirPickerEvent& event)
{
    // Get the selected file
    std::string file = BitmapFilePicker->GetPath().ToStdString();
    std::string ext = "bmp";

    std::string path = add_ext(file, ext);

    // Check if the bitmap has valid data
    if(bitmap->IsOk())
    {
        wxImage image = bitmap->ConvertToImage();           // Convert the wxBitmap to a wxImage
        image.SaveFile(wxString(path), wxBITMAP_TYPE_BMP);  // Save the wxImage to the file path as a BMP
    }
}

// Adds the extension ext, seperated by a period if it is not already at the end of the path
const std::string ClickAndDrawFrame::add_ext(const std::string path, const std::string ext)
{
    // pos holds the position of the found character
    std::string::size_type pos;

    // returns the position of the last '.', or string::npos if not found
    pos = path.find_last_of('.');

    if (pos == std::string::npos)   // '.' was not found
    {
        return path + "." + ext;
    }

    // An extension exists, so grab it
    std::string existing_ext = path.substr(pos+1);

    // Check if it's the one we want
    if (existing_ext == ext)
    {
        return path; // If existing ext was the right ext, return path unaltered
    }
    else
    {
        return path + "." + ext; // else add the extension and return that
    }
}

void ClickAndDrawFrame::writePointsToFile(std::string file)
{
    // These structs will be loaded with data to write to the file
    struct file_header header;
    struct light_point point;

    // Open the file for writing in binary mode
    std::FILE* f = std::fopen(file.c_str(), "wb");

    // Check if the file opened correctly, else print an error message and return
    // TODO: Popup a dialog for this
    if(!f) {
        std::perror("Failed to open file");
        return;
    }

    // Get the data to pack into the header struct
    int thickness = wxAtoi(ThicknessPicker->GetString(ThicknessPicker->GetSelection()));
    uint32_t color = ColorPicker->GetColour().GetRGB();
    size_t vector_size = drawPoints->size();

    // Make the header struct from the data we got earlier
    header.thickness = thickness;
    header.color = color;
    header.vector_size = vector_size;

    // Write the header struct to the head of the file
    std::fwrite(&header, sizeof(file_header),1,f);


    for(wxPoint& p : *drawPoints) {
        point.x = p.x;
        point.y = p.y;
        std::fwrite(&point, sizeof(light_point),1,f);
    }

    // Close the door on your way out
    std::fclose(f);
}

void ClickAndDrawFrame::readPointsFromFile(std::string file)
{
    // These structs will contain the data read back from the file
    struct file_header header;
    struct light_point point;

    // Open up the file for reading in binary mode
    std::FILE* f = std::fopen(file.c_str(),"rb");

    // Check if the file opened correctly, else print an error message and return
    // TODO: Popup a dialog for this
    if(!f) {
        std::perror("Failed to open file");
        return;
    }

    // Read the header data back from the file
    std::fread(&header, sizeof(file_header), 1, f);

    // Set up the drawPoints vector
    drawPoints->clear();
    drawPoints->reserve(header.vector_size);

    // Set the thickness picker. This happens in three steps
    std::string thicknessString = std::to_string(header.thickness); // First, convert the int to a string
    int choice = ThicknessPicker->FindString(thicknessString); // Then find that string, this returns an index
    ThicknessPicker->SetSelection(choice); // Finally, use the index to set the selection

    // Set the color picker color
    wxColor *color = new wxColor();
    color->SetRGB(header.color);
    ColorPicker->SetColour(*color);

    // Read in the points, loading them into light_point structs and using that to construct new wxPoints
    // Finally, push the new wxPoints back onto the vector
    for(unsigned int i = 0; i < header.vector_size; i++)
    {
        wxPoint* p = new wxPoint();

        std::fread(&point, sizeof(light_point),1,f);

        p->x = point.x;
        p->y = point.y;

        drawPoints->push_back(*p);
    }

    // Don't forget to close the file when you're done.
    std::fclose(f);
}

void ClickAndDrawFrame::OnSavePointsFilePickerFileChanged(wxFileDirPickerEvent& event)
{
    std::string file = add_ext(event.GetPath().ToStdString(),"dd");
    writePointsToFile(file);
}

void ClickAndDrawFrame::OnLoadPointsFilePickerFileChanged(wxFileDirPickerEvent& event)
{
    readPointsFromFile(event.GetPath().ToStdString());
}
