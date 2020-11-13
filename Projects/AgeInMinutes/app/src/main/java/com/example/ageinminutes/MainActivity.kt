package com.example.ageinminutes

import android.app.DatePickerDialog
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*
import java.text.SimpleDateFormat
import java.util.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        btnDatePicker.setOnClickListener {view ->
            clickDatePicker(view)
           // Toast.makeText(this, "Button Works" , Toast.LENGTH_LONG).show()
        }
    }

    fun clickDatePicker(view: View){

        val myCalendar= Calendar.getInstance()
        val TodaysYear = myCalendar.get(Calendar.YEAR)
        val TodaysMonth=myCalendar.get(Calendar.MONTH)
        val TodaysDay = myCalendar.get(Calendar.DAY_OF_MONTH)
        DatePickerDialog(this,
            DatePickerDialog.OnDateSetListener {
                    view, SelectedYear, SelectedMonth, SelectedDay ->

                Toast.makeText(this, "The chosen date is $SelectedDay/${SelectedMonth+1}/$SelectedYear", Toast.LENGTH_LONG).show()
                val selectedDate = "$SelectedDay/${SelectedMonth+1}/$SelectedYear"
                tvSelectedDate.setText(selectedDate)
                val sdf = SimpleDateFormat("dd/MM/yyyy" , Locale.ENGLISH)
                val theDate = sdf.parse(selectedDate)
                val selectedDateInMinutes = theDate!!.time / 60000
                val currentDate= sdf.parse(sdf.format(System.currentTimeMillis()))
                val currentDateToMinutes= currentDate!!.time/60000
                val differenceInMinutes = currentDateToMinutes-selectedDateInMinutes
                //val diffInDays=differenceInMinutes/1440
                tvAgeInMinutes.setText(differenceInMinutes.toString())



            }, TodaysYear, TodaysMonth, TodaysDay).show()
    }
}