﻿using Health_Organizer.Data;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Health_Organizer.Data_Model_Classes;
using System.Diagnostics;

namespace Health_Organizer
{
    public sealed partial class AnalysisPage : Page
    {

        private NavigationHelper navigationHelper;
        private ObservableDictionary defaultViewModel = new ObservableDictionary();

        public List<AnalysisSampleDataItem> mainItemList;
        public List<string> cityList;
        public List<string> diseaseList;
        public List<string> allergyList;
        public List<string> addictionList;
        public List<string> vaccinationList;
        public List<string> operationList;
        public Dictionary<string, string> city2state;

        bool ByDateFlag, CityFlag, StateFlag, SexFlag, StatusFlag, BGFlag, DiseaseFlag, AllergyFlag,
            AddictionFlag, VaccineFlag, OperationFlag;

        Int16 sexMale = 0;
        Int16 isMarried = 0;

        public ObservableDictionary DefaultViewModel
        {
            get { return this.defaultViewModel; }
        }

        public NavigationHelper NavigationHelper
        {
            get { return this.navigationHelper; }
        }


        public AnalysisPage()
        {
            this.InitializeComponent();
            this.navigationHelper = new NavigationHelper(this);
            this.navigationHelper.LoadState += navigationHelper_LoadState;
            this.navigationHelper.SaveState += navigationHelper_SaveState;
        }

        private async void navigationHelper_LoadState(object sender, LoadStateEventArgs e)
        {
            var sample = await AnalysisPageDataSoure.GetItemsAsync();
            this.DefaultViewModel["Items"] = sample;

            RecordGrid.SelectedItem = null;

            mainItemList = RecordGrid.Items.OfType<AnalysisSampleDataItem>().ToList();
            fillAllLists();
            fillAllComboBox();

            this.AnalysisResetBox();
            this.AnalysisResetFlag();
            this.AnalysisResetDateBox();
        }

        private void navigationHelper_SaveState(object sender, SaveStateEventArgs e)
        {
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            navigationHelper.OnNavigatedTo(e);
        }

        protected override void OnNavigatedFrom(NavigationEventArgs e)
        {
            navigationHelper.OnNavigatedFrom(e);
        }

        private void fillAllLists()
        {
            cityList = new List<string>();
            city2state = new Dictionary<string, string>();
            diseaseList = new List<string>();
            allergyList = new List<string>();
            addictionList = new List<string>();
            vaccinationList = new List<string>();
            operationList = new List<string>();

            //Adding city and corrosponding State to Lists
            foreach (AnalysisSampleDataItem item in mainItemList)
            {
                if (!cityList.Contains(item.City))
                {
                    cityList.Add(item.City);

                    if (!city2state.ContainsValue(item.State))
                    {
                        city2state.Add(item.City, item.State);
                    }

                }

                //Adding disease to list
                foreach (string diseases in item.Diseases.Values)
                {
                    if (!diseaseList.Contains(diseases))
                    {
                        diseaseList.Add(diseases);
                    }
                }

                //Adding allergies to list
                foreach (string allergy in item.Allergy)
                {
                    if (!allergyList.Contains(allergy))
                    {
                        allergyList.Add(allergy);
                    }
                }

                //Adding addictions to list
                foreach (string addiction in item.Addiction)
                {
                    if (!addictionList.Contains(addiction))
                    {
                        addictionList.Add(addiction);
                    }
                }

                foreach (string vaccine in item.Vaccines.Values)
                {
                    if (!vaccinationList.Contains(vaccine))
                    {
                        vaccinationList.Add(vaccine);
                    }
                }

                foreach (string operation in item.Operation)
                {
                    if (!operationList.Contains(operation))
                    {
                        operationList.Add(operation);
                    }
                }

            }
        }

        private void fillAllComboBox()
        {
            AnalysisAllCheck.IsChecked = true;
            AnalysisAllCatCheck.IsChecked = true;

            for (Int16 i = 0; i < 31; i++)
            {
                AnalysisFromDayComboBox.Items.Add(i + 1);
                AnalysisToDayComboBox.Items.Add(i + 1);
            }

            for (Int16 i = 1980; i < DateTime.Now.Year; i++)
            {
                AnalysisFromYearComboBox.Items.Add(i + 1);
                AnalysisToYearComboBox.Items.Add(i + 1);
            }

            this.AnalysisResetDateBox();

            foreach (string city in cityList)
            {
                AnalysisCityBox.Items.Add(city);
            }

            foreach (string state in city2state.Values)
            {
                AnalysisStateBox.Items.Add(state);
            }

            foreach (string disease in diseaseList)
            {
                AnalysisDiseaseBox.Items.Add(disease);
            }

            foreach (string allergy in allergyList)
            {
                AnalysisAllergyBox.Items.Add(allergy);
            }

            foreach (string addiction in addictionList)
            {
                AnalysisAddictionBox.Items.Add(addiction);
            }

            foreach (string vaccine in vaccinationList)
            {
                AnalysisVaccinationBox.Items.Add(vaccine);
            }

            foreach (string operation in operationList)
            {
                AnalysisOperationsBox.Items.Add(operation);
            }

        }

        private void AnalysisAllChecked(object sender, RoutedEventArgs e)
        {
            sexMale = 0;
            AnalysisMaleCheck.IsChecked = false;
            AnalysisFemaleCheck.IsChecked = false;
        }

        private void AnalysisMaleChecked(object sender, RoutedEventArgs e)
        {
            sexMale = 1;
            AnalysisFemaleCheck.IsChecked = false;
            AnalysisAllCheck.IsChecked = false;
        }

        private void AnalysisFemaleChecked(object sender, RoutedEventArgs e)
        {
            sexMale = -1;
            AnalysisMaleCheck.IsChecked = false;
            AnalysisAllCheck.IsChecked = false;
        }

        private void AnalysisAllCatChecked(object sender, RoutedEventArgs e)
        {
            isMarried = 0;
            AnalysisMarriedCheck.IsChecked = false;
            AnalysisUnmarriedCheck.IsChecked = false;
        }

        private void AnalysisMarriedChecked(object sender, RoutedEventArgs e)
        {
            isMarried = 1;
            AnalysisUnmarriedCheck.IsChecked = false;
            AnalysisAllCatCheck.IsChecked = false;
        }

        private void AnalysisUnmarriedChecked(object sender, RoutedEventArgs e)
        {
            isMarried = -1;
            AnalysisMarriedCheck.IsChecked = false;
            AnalysisAllCatCheck.IsChecked = false;
        }

        private void AnalysisByDateChecked(object sender, RoutedEventArgs e)
        {
            ByDateFlag = true;
            this.AnalysisDateBoxEnable();
        }

        private void AnalysisCitySelected(object sender, SelectionChangedEventArgs e)
        {
            string state;
            if (AnalysisCityBox.SelectedIndex != -1)
            {
                if (city2state.TryGetValue(AnalysisCityBox.SelectedItem.ToString(), out state))
                {
                    AnalysisStateBox.SelectedItem = state;
                }
            }
        }

        private void AnalysisResetFieldsClicked(object sender, RoutedEventArgs e)
        {
            this.AnalysisResetBox();
            this.AnalysisResetFlag();
            this.AnalysisResetDateBox();
            this.AnalysisDateBoxDisable();
            this.DefaultViewModel["Items"] = mainItemList;
            RecordGrid.SelectedItem = null;
        }

        private void AnalysisSearchClicked(object sender, RoutedEventArgs e)
        {
            this.AnalysisValidateFields();
            this.AnalysisSetFlags();
            this.updateView();
            RecordGrid.SelectedItem = null;
        }

        private void updateView()
        {
            List<AnalysisSampleDataItem> resultList = new List<AnalysisSampleDataItem>();

            foreach (AnalysisSampleDataItem item in mainItemList)
            {
                if (ByDateFlag)
                {
                    int lastDateOn = item.DatesVisited.Count;

                    if (lastDateOn > 0)
                    {
                        DateTime lastDate = ExtraModules.ConvertStringToDateTime(item.DatesVisited.ElementAt(lastDateOn - 1));
                        DateTime fromDate = new DateTime(Convert.ToInt32(AnalysisFromYearComboBox.SelectedItem), AnalysisFromMonthComboBox.SelectedIndex + 1, Convert.ToInt32(AnalysisFromDayComboBox.SelectedItem));
                        DateTime toDate = new DateTime(Convert.ToInt32(AnalysisToYearComboBox.SelectedItem), AnalysisToMonthComboBox.SelectedIndex + 1, Convert.ToInt32(AnalysisToDayComboBox.SelectedItem));

                        if (!(fromDate <= lastDate && toDate >= lastDate))
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }

                }


                if (CityFlag)
                {
                    if (!AnalysisCityBox.SelectedItem.ToString().Equals(item.City))
                    {
                        continue;
                    }
                }

                if (StateFlag)
                {
                    if (!AnalysisStateBox.SelectedItem.ToString().Equals(item.State))
                    {
                        continue;
                    }
                }

                if (SexFlag)
                {
                    switch (sexMale)
                    {
                        case 1: if (item.Sex != 'M')
                            {
                                continue;
                            }
                            break;
                        case -1: if (item.Sex != 'F')
                            {
                                continue;
                            }
                            break;
                    }
                }

                if (StatusFlag)
                {
                    switch (isMarried)
                    {
                        case 1: if (!item.Married)
                            {
                                continue;
                            }
                            break;
                        case -1: if (!item.Married)
                            {
                                continue;
                            }
                            break;
                    }
                }

                if (BGFlag)
                {
                    if (!AnalysisBloodGroupBox.SelectedItem.ToString().Equals(item.BloodGroup))
                    {
                        continue;
                    }
                }

                if (DiseaseFlag)
                {
                    bool found = false;
                    foreach (string disease in item.Diseases.Values)
                    {
                        if (AnalysisDiseaseBox.SelectedItem.ToString().Equals(disease))
                        {
                            found = true;
                        }
                    }

                    if (!found)
                    {
                        continue;
                    }
                }

                if (AllergyFlag)
                {
                    bool found = false;
                    foreach (string allergy in item.Allergy)
                    {
                        if (AnalysisAllergyBox.SelectedItem.ToString().Equals(allergy))
                        {
                            found = true;
                        }
                    }

                    if (!found)
                    {
                        continue;
                    }
                }

                if (AddictionFlag)
                {
                    bool found = false;
                    foreach (string addiction in item.Addiction)
                    {
                        if (AnalysisAddictionBox.SelectedItem.ToString().Equals(addiction))
                        {
                            found = true;
                        }
                    }

                    if (!found)
                    {
                        continue;
                    }
                }

                if (VaccineFlag)
                {
                    bool found = false;
                    foreach (string vaccine in item.Vaccines.Values)
                    {
                        if (AnalysisVaccinationBox.SelectedItem.ToString().Equals(vaccine))
                        {
                            found = true;
                        }
                    }

                    if (!found)
                    {
                        continue;
                    }
                }

                if (OperationFlag)
                {
                    bool found = false;
                    foreach (string operation in item.Operation)
                    {
                        if (AnalysisOperationsBox.SelectedItem.ToString().Equals(operation))
                        {
                            found = true;
                        }
                    }

                    if (!found)
                    {
                        continue;
                    }
                }

                resultList.Add(item);
            }
            this.DefaultViewModel["Items"] = resultList;
        }

        private void AnalysisResetBox()
        {
            AnalysisCityBox.SelectedIndex = -1;
            AnalysisStateBox.SelectedIndex = -1;
            AnalysisByDate.IsChecked = false;
            AnalysisAllCheck.IsChecked = true;
            AnalysisAllCatCheck.IsChecked = true;
            AnalysisMaleCheck.IsChecked = false;
            AnalysisFemaleCheck.IsChecked = false;
            AnalysisMarriedCheck.IsChecked = false;
            AnalysisUnmarriedCheck.IsChecked = false;
            AnalysisBloodGroupBox.SelectedIndex = -1;
            AnalysisDiseaseBox.SelectedIndex = -1;
            AnalysisAllergyBox.SelectedIndex = -1;
            AnalysisAddictionBox.SelectedIndex = -1;
            AnalysisVaccinationBox.SelectedIndex = -1;
            AnalysisOperationsBox.SelectedIndex = -1;

            this.AnalysisDateBoxDisable();
        }

        private void AnalysisResetDateBox()
        {
            AnalysisFromDayComboBox.SelectedIndex = 0;
            AnalysisFromMonthComboBox.SelectedIndex = 0;
            AnalysisFromYearComboBox.SelectedIndex = 0;
            AnalysisToDayComboBox.SelectedItem = DateTime.Now.Day;
            AnalysisToMonthComboBox.SelectedIndex = DateTime.Now.Month - 1;
            AnalysisToYearComboBox.SelectedItem = DateTime.Now.Year;
        }

        private void AnalysisResetFlag()
        {
            ByDateFlag = false;
            CityFlag = false;
            StateFlag = false;
            SexFlag = false;
            StatusFlag = false;
            BGFlag = false;
            DiseaseFlag = false;
            AllergyFlag = false;
            AddictionFlag = false;
            VaccineFlag = false;
            OperationFlag = false;
        }

        private void AnalysisValidateFields()
        {
            DateTime toDate = new DateTime(Convert.ToInt16(AnalysisToYearComboBox.SelectedItem), AnalysisToMonthComboBox.SelectedIndex + 1, Convert.ToInt16(AnalysisToDayComboBox.SelectedItem));
            DateTime fromDate = new DateTime(Convert.ToInt16(AnalysisFromYearComboBox.SelectedItem), AnalysisFromMonthComboBox.SelectedIndex + 1, Convert.ToInt16(AnalysisFromDayComboBox.SelectedItem));

            if (toDate < fromDate)
            {
                AnalysisFromDayComboBox.SelectedItem = AnalysisToDayComboBox.SelectedItem;
                AnalysisFromMonthComboBox.SelectedIndex = AnalysisToMonthComboBox.SelectedIndex;
                AnalysisFromYearComboBox.SelectedItem = AnalysisToYearComboBox.SelectedItem;
            }
        }

        private void AnalysisSetFlags()
        {
            if (AnalysisCityBox.SelectedIndex != -1)
            {
                CityFlag = true;
            }
            if (AnalysisStateBox.SelectedIndex != -1)
            {
                StateFlag = true;
            }
            if (sexMale != 0)
            {
                SexFlag = true;
            }
            if (isMarried != 0)
            {
                StatusFlag = true;
            }
            if (AnalysisBloodGroupBox.SelectedIndex != -1)
            {
                BGFlag = true;
            }
            if (AnalysisDiseaseBox.SelectedIndex != -1)
            {
                DiseaseFlag = true;
            }
            if (AnalysisAllergyBox.SelectedIndex != -1)
            {
                AllergyFlag = true;
            }
            if (AnalysisVaccinationBox.SelectedIndex != -1)
            {
                VaccineFlag = true;
            }
            if (AnalysisOperationsBox.SelectedIndex != -1)
            {
                OperationFlag = true;
            }
        }

        private void AnalysisDateBoxDisable()
        {
            AnalysisFromDayComboBox.IsEnabled = false;
            AnalysisFromMonthComboBox.IsEnabled = false;
            AnalysisFromYearComboBox.IsEnabled = false;
            AnalysisToDayComboBox.IsEnabled = false;
            AnalysisToMonthComboBox.IsEnabled = false;
            AnalysisToYearComboBox.IsEnabled = false;
        }

        private void AnalysisDateBoxEnable()
        {
            AnalysisFromDayComboBox.IsEnabled = true;
            AnalysisFromMonthComboBox.IsEnabled = true;
            AnalysisFromYearComboBox.IsEnabled = true;
            AnalysisToDayComboBox.IsEnabled = true;
            AnalysisToMonthComboBox.IsEnabled = true;
            AnalysisToYearComboBox.IsEnabled = true;
        }


    }
}
