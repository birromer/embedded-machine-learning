#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[2] <= 290.81100000000004) {
		if (features[346] <= 30.38995) {
			if (features[1] <= 135.239) {
				if (features[261] <= 33.56935) {
					return ( "jazz");
				} else {
					if (features[83] <= 33.6966) {
						return ( "classical");
					} else {
						if (features[0] <= 45.8699) {
							return ( "jazz");
						} else {
							return ( "classical");
						}
					}
				}
			} else {
				if (features[3] <= 193.3485) {
					return ( "jazz");
				} else {
					return ( "classical");
				}
			}
		} else {
			if (features[257] <= 90.7259) {
				if (features[14] <= 204.4305) {
					if (features[195] <= 7.958925000000001) {
						if (features[3] <= 91.98724999999999) {
							return ( "disco");
						} else {
							return ( "reggae");
						}
					} else {
						if (features[0] <= 65.18945) {
							return ( "pop");
						} else {
							return ( "rock");
						}
					}
				} else {
					if (features[2] <= 272.27) {
						return ( "jazz");
					} else {
						return ( "country");
					}
				}
			} else {
				return ( "blues");
			}
		}
	} else {
		if (features[244] <= 47.1681) {
			if (features[260] <= 209.0085) {
				if (features[4] <= 254.688) {
					return ( "jazz");
				} else {
					if (features[0] <= 64.68105) {
						return ( "rock");
					} else {
						return ( "metal");
					}
				}
			} else {
				if (features[59] <= 137.79399999999998) {
					if (features[258] <= 781.659) {
						if (features[261] <= 756.3689999999999) {
							if (features[152] <= 13.3686) {
								if (features[479] <= 0.6742859999999999) {
									if (features[22] <= 77.11500000000001) {
										return ( "blues");
									} else {
										if (features[20] <= 179.5625) {
											return ( "jazz");
										} else {
											if (features[0] <= 69.80709999999999) {
												return ( "country");
											} else {
												return ( "classical");
											}
										}
									}
								} else {
									if (features[24] <= 230.5615) {
										if (features[5] <= 246.7975) {
											if (features[270] <= 270.08349999999996) {
												if (features[36] <= 45.05025) {
													return ( "pop");
												} else {
													return ( "classical");
												}
											} else {
												return ( "jazz");
											}
										} else {
											if (features[407] <= 20.938299999999998) {
												if (features[270] <= 594.2185) {
													return ( "country");
												} else {
													return ( "jazz");
												}
											} else {
												if (features[3] <= 773.29) {
													return ( "classical");
												} else {
													return ( "blues");
												}
											}
										}
									} else {
										if (features[0] <= 83.66425000000001) {
											return ( "jazz");
										} else {
											return ( "reggae");
										}
									}
								}
							} else {
								if (features[263] <= 365.0135) {
									if (features[353] <= 113.4025) {
										if (features[265] <= 250.9145) {
											if (features[66] <= 82.66745) {
												if (features[283] <= 126.5395) {
													return ( "rock");
												} else {
													return ( "disco");
												}
											} else {
												return ( "metal");
											}
										} else {
											if (features[178] <= 38.9892) {
												if (features[297] <= 300.9435) {
													return ( "rock");
												} else {
													return ( "country");
												}
											} else {
												if (features[5] <= 580.1985) {
													return ( "disco");
												} else {
													return ( "jazz");
												}
											}
										}
									} else {
										return ( "blues");
									}
								} else {
									if (features[474] <= 4.096235) {
										if (features[1] <= 269.18) {
											return ( "jazz");
										} else {
											return ( "blues");
										}
									} else {
										if (features[95] <= 48.97095) {
											if (features[156] <= 16.098100000000002) {
												if (features[0] <= 144.61265) {
													return ( "classical");
												} else {
													return ( "reggae");
												}
											} else {
												return ( "country");
											}
										} else {
											if (features[7] <= 573.4555) {
												if (features[1] <= 585.3299999999999) {
													return ( "disco");
												} else {
													return ( "rock");
												}
											} else {
												return ( "blues");
											}
										}
									}
								}
							}
						} else {
							if (features[18] <= 194.851) {
								return ( "blues");
							} else {
								return ( "rock");
							}
						}
					} else {
						if (features[111] <= 28.26305) {
							if (features[6] <= 444.9995) {
								if (features[484] <= 0.7776875000000001) {
									if (features[0] <= 238.6215) {
										if (features[10] <= 163.61599999999999) {
											return ( "blues");
										} else {
											if (features[0] <= 132.55865) {
												return ( "jazz");
											} else {
												return ( "disco");
											}
										}
									} else {
										return ( "hiphop");
									}
								} else {
									if (features[4] <= 665.7574999999999) {
										if (features[33] <= 143.874) {
											return ( "reggae");
										} else {
											return ( "jazz");
										}
									} else {
										if (features[0] <= 334.0815) {
											return ( "reggae");
										} else {
											return ( "hiphop");
										}
									}
								}
							} else {
								if (features[485] <= 1.30359) {
									if (features[17] <= 220.2735) {
										if (features[366] <= 13.655750000000001) {
											if (features[0] <= 95.0204) {
												return ( "reggae");
											} else {
												return ( "jazz");
											}
										} else {
											return ( "blues");
										}
									} else {
										return ( "country");
									}
								} else {
									if (features[301] <= 81.44319999999999) {
										if (features[1] <= 1879.335) {
											return ( "rock");
										} else {
											return ( "pop");
										}
									} else {
										if (features[18] <= 294.183) {
											if (features[0] <= 194.42649999999998) {
												return ( "disco");
											} else {
												if (features[1] <= 1185.6515) {
													return ( "reggae");
												} else {
													return ( "pop");
												}
											}
										} else {
											return ( "jazz");
										}
									}
								}
							}
						} else {
							if (features[1] <= 999.799) {
								if (features[5] <= 575.7294999999999) {
									if (features[374] <= 55.14915) {
										if (features[4] <= 378.2085) {
											return ( "hiphop");
										} else {
											return ( "disco");
										}
									} else {
										if (features[4] <= 549.886) {
											return ( "reggae");
										} else {
											return ( "hiphop");
										}
									}
								} else {
									if (features[427] <= 32.15795) {
										if (features[48] <= 109.3285) {
											return ( "country");
										} else {
											if (features[1] <= 649.5185) {
												if (features[0] <= 182.938) {
													return ( "classical");
												} else {
													return ( "rock");
												}
											} else {
												return ( "metal");
											}
										}
									} else {
										if (features[21] <= 319.5795) {
											if (features[511] <= 24.318849999999998) {
												if (features[169] <= 30.3815) {
													return ( "disco");
												} else {
													return ( "rock");
												}
											} else {
												if (features[0] <= 137.757) {
													return ( "reggae");
												} else {
													return ( "pop");
												}
											}
										} else {
											return ( "disco");
										}
									}
								}
							} else {
								if (features[41] <= 134.05) {
									if (features[377] <= 117.1515) {
										if (features[297] <= 111.47) {
											if (features[21] <= 119.8255) {
												return ( "hiphop");
											} else {
												if (features[6] <= 546.8655) {
													return ( "reggae");
												} else {
													return ( "rock");
												}
											}
										} else {
											if (features[7] <= 176.45100000000002) {
												return ( "disco");
											} else {
												if (features[9] <= 705.739) {
													return ( "hiphop");
												} else {
													return ( "country");
												}
											}
										}
									} else {
										if (features[2] <= 2365.855) {
											return ( "reggae");
										} else {
											if (features[0] <= 289.794) {
												return ( "jazz");
											} else {
												return ( "hiphop");
											}
										}
									}
								} else {
									if (features[63] <= 81.84485000000001) {
										return ( "pop");
									} else {
										if (features[504] <= 13.1646) {
											if (features[6] <= 686.155) {
												return ( "rock");
											} else {
												if (features[14] <= 334.2765) {
													return ( "blues");
												} else {
													return ( "reggae");
												}
											}
										} else {
											if (features[1] <= 1573.2350000000001) {
												return ( "disco");
											} else {
												if (features[13] <= 229.6825) {
													return ( "reggae");
												} else {
													return ( "hiphop");
												}
											}
										}
									}
								}
							}
						}
					}
				} else {
					if (features[300] <= 139.95749999999998) {
						if (features[283] <= 413.56100000000004) {
							return ( "metal");
						} else {
							if (features[0] <= 194.5625) {
								return ( "classical");
							} else {
								return ( "disco");
							}
						}
					} else {
						if (features[71] <= 195.0755) {
							if (features[257] <= 662.7525) {
								if (features[5] <= 600.053) {
									return ( "disco");
								} else {
									if (features[0] <= 254.6605) {
										return ( "rock");
									} else {
										return ( "metal");
									}
								}
							} else {
								if (features[382] <= 97.3621) {
									if (features[362] <= 91.36699999999999) {
										if (features[371] <= 99.12785) {
											if (features[8] <= 340.96299999999997) {
												return ( "reggae");
											} else {
												if (features[287] <= 344.899) {
													return ( "country");
												} else {
													return ( "rock");
												}
											}
										} else {
											if (features[4] <= 1217.635) {
												return ( "blues");
											} else {
												return ( "hiphop");
											}
										}
									} else {
										if (features[9] <= 575.3130000000001) {
											if (features[1] <= 1794.74) {
												return ( "disco");
											} else {
												return ( "hiphop");
											}
										} else {
											if (features[0] <= 423.049) {
												return ( "blues");
											} else {
												return ( "pop");
											}
										}
									}
								} else {
									if (features[3] <= 2170.98) {
										return ( "hiphop");
									} else {
										if (features[0] <= 1073.2355) {
											return ( "reggae");
										} else {
											return ( "pop");
										}
									}
								}
							}
						} else {
							if (features[54] <= 209.2495) {
								if (features[0] <= 373.9635) {
									return ( "disco");
								} else {
									return ( "country");
								}
							} else {
								return ( "metal");
							}
						}
					}
				}
			}
		} else {
			if (features[3] <= 1859.12) {
				if (features[256] <= 300.2975) {
					return ( "disco");
				} else {
					if (features[36] <= 515.171) {
						if (features[0] <= 233.6375) {
							return ( "reggae");
						} else {
							if (features[36] <= 79.30015) {
								return ( "reggae");
							} else {
								return ( "pop");
							}
						}
					} else {
						return ( "rock");
					}
				}
			} else {
				if (features[4] <= 1106.29) {
					return ( "pop");
				} else {
					return ( "hiphop");
				}
			}
		}
	}
}