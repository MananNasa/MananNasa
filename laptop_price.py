import streamlit as st
import pickle
import numpy as np

# Load the trained model and dataframe
pipe = pickle.load(open("pipe.pkl", 'rb'))
df = pickle.load(open("df.pkl", 'rb'))

# App title
st.title("💻 Laptop Price Predictor")

# Input fields for the user
Company = st.selectbox('Brand', sorted(df['Brand'].unique()))
RAM = st.selectbox('RAM (GB)', sorted(df["RAM (GB)"].unique()))
Memory = st.selectbox('Storage (GB)', sorted(df["Storage (GB)"].unique()))
GPU = st.selectbox('GPU', sorted(df["GPU"].unique()))
SCREEN_S = st.selectbox("Screen Size (inches)", sorted(df["Screen Size (inches)"].unique()))
Battery = st.selectbox("Battery Life (hours)", sorted(df["Battery Life (hours)"].unique()))
CPU = st.selectbox("CPU Brand", sorted(df["cpu brand"].unique()))

# Predict button
if st.button("Predict Price"):
    query = np.array([Company, RAM, Memory, GPU, SCREEN_S, Battery, CPU]).reshape(1, -1)
    predicted_price = round(np.exp(pipe.predict(query)[0]), 2)
    st.success(f"💰 Predicted Price: ₹{predicted_price}")
